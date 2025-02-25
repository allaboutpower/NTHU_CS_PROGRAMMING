#include<stdio.h>
#include<stdlib.h>
#include<string.h>



typedef struct _Node{
    int number;
    struct _Node *next;
}Node;


Node *createList(int n)
{
    Node* head = (Node*)malloc(sizeof(Node));
    head->number = 1;

    Node* cur = head;

    for(int t=2; t<=n; t++){
        cur->next=(Node*)malloc(sizeof(Node));
        cur = cur->next ;
        cur->number = t;
    }
    cur->next = head;
    return head;
}

void freeList(Node* head)
{
    free(head);
}

int solveJosephus(Node **head, int step)
{
    
    //count n in circle
    int n = 0 ;
    Node *delete, *cur, *tmp;
    for(tmp = *head; tmp->number > n ; tmp = tmp->next, n++);

    //delete step    
    while(n-1){
        int k_mod = (((step-1)%n)+n-1)%n;
        cur = *head;

        for(int i=0; i<k_mod; i++){
            cur = cur->next;
        }

        Node *delete = cur->next;
        cur->next = cur->next->next;
        *head = cur->next;
        free(delete);
        n-- ;
    }
    return (*head)->number;

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