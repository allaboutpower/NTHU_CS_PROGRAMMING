#include<stdio.h>
#include<stdlib.h>

typedef struct _Node{
    int number;
    struct _Node* next;
}Node;

Node *createList(int n)
{
    Node *nd = (Node*)malloc(sizeof(Node));
    nd->next=NULL;
    nd->number = n;
    return nd; 
}
void freeList(Node* head)
{
    free(head);
    return;
}
int solveJosephus(Node **head, int step)
{
    int n = (*head)->number;
    return recursive(n,step);
}

int recursive(int n, int k){
    if(n==1)return 1;
    return (recursive(n-1,k)+k-1)%n+1;
}

int main()
{
    int n, k;
    while( scanf("%d%d", &n, &k)!=EOF )
   {
        Node *head;
        head = createList(n);
        printf( "%d\n", solveJosephus(&head, k) );
        freeList(head);
    }
    return 0;
}