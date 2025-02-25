#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stddef.h>

typedef struct _NODE
{
    char color[10];
    struct _NODE *next;
} Node;

void show(Node **head) {
    Node *now = (*head)->next;
    while(now!=NULL) {
        printf("%s ", now->color);
        now = now->next;
    }
    puts("");
}

void insert(Node* *head, char* color, int dest){
    Node *now = (*head);
    
    for(int idx = 0; now->next != NULL && idx != dest; now = now->next , idx++);
    
    Node *new = (Node*)malloc(sizeof(Node));
    strcpy(new->color, color);
    new->next = now->next;
    now->next = new; 
}
void erase1(Node* *head, int dest){
    Node *now = (*head);
    Node *pre = NULL;
    
    for(int idx = 0; now->next != NULL && idx != dest; pre = now, now = now->next, idx++);
    if(pre == NULL){return;}
    pre->next = now->next;
    free(now);
}
void erase2(Node* *head, char* color){
    Node *now = (*head);
    Node *pre = NULL;
    while(now != NULL){
        if(strcmp(now->color, color) == 0){
            pre->next = now->next;
            free(now);
            now = pre;
        }
        pre = now;
        now = now->next;
    }   
    
}
void reverse(Node* *head, int dest1, int dest2){

    if(dest1>=dest2)return;
    Node *now = (*head), *left = NULL;
    int idx;

    if(now == NULL || now->next== NULL)return;
    for(idx = 0; now != NULL && idx != dest1; left = now, now = now->next, idx++);

    while (now->next != NULL && idx < dest2){ //idx=dest1
        Node *next = now->next;
        now->next = next->next;   // 將 now 跳過 next
        next->next = left->next;  // 將 next 插入到 left 之後
        left->next = next;        // 更新 left 指向新插入的節點

        idx++;
    }
}

int n;
char buf[100];
int num1, num2;
Node *head;

int main() {
    head = (Node*)malloc(sizeof(Node)); // create an empty node
    memset(head->color,'\0',sizeof(head->color));
    head->next = NULL;
    scanf("%d",&n);
    while(n--) {
        canf("%s",buf);
        if(!strcmp(buf,"insert")) {
            scanf("%s%d",buf,&num1);
            insert(&head, buf, num1); // insert <color> <dest>
        }
        else if(!strcmp(buf,"erase1")) {
            scanf("%d",&num1);
            erase1(&head, num1); // erase1 <dest>
        }
        else if(!strcmp(buf,"erase2")) {
            scanf("%s",buf);
            erase2(&head, buf); // erase2 <color>
        }
        else if(!strcmp(buf,"reverse")) {
            scanf("%d%d",&num1,&num2);
            reverse(&head, num1, num2); // reverse <dest1> <dest2>
        }
        else if(!strcmp(buf,"show")) {
            show(&head);
        }
    }
    return 0;
}



