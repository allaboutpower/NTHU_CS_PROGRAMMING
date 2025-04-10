#include <stdio.h>
#include <stdlib.h>

typedef struct _Node{
    int number;
    struct _Node* next;
}Node;

Node *createList(int n)
{
    Node* head = (Node*)malloc(sizeof(Node));
    head->number = n;
    head->next = NULL;
    return head;
}

void freeList(Node* head)
{
    free(head);
    return;
}
int solveJosephus(Node **head, int step)
{   
    int n = (*head)->number;
    //printf("%d %d\n", n, step);
    return recursive(n, step);
}

int recursive(int n, int k){
    if(n=1) return 1;
    if(recursive(n-1, k)>n){
        return recursive(n-1, k)+k-n;
    }
    return recursive(n-1, k)+k;   

}



int main()
{
    int n, k;
    while( scanf("%d%d", &n, &k)!= EOF )
   {
        Node *head;
        head = createList(n);
        printf( "%d\n", solveJosephus(&head, k) );
        freeList(head);
    }
    return 0;
}