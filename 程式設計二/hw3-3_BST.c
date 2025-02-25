#include<stdio.h>
#include<stdlib.h>

#define MAX 2000000


/*
10 5
4 7 9 20 31 46 50 56 76 96 //l=1, r=10 
19
50
96
7
100
    */


typedef struct _NODE {
    int num, id;
    struct _NODE *left, *right;
} Node;

void build_tree(Node **now,int *lst, int l, int r) {
    if(l>r) return;
    (*now) = (Node*)malloc(sizeof(Node));
    (*now)->left = (*now)->right = NULL;

    if(l==r) {
        (*now)->num = lst[l];
        (*now)->id  = l;
    }
    else {
        int mid = (l+r)/2;
        (*now)->id = mid;
        (*now)->num = lst[mid]; 
        build_tree( &((*now)->left) , lst, l, mid-1);
        build_tree( &((*now)->right) , lst, mid+1, r );
    }
}

int search(Node *now, int target) {
    if(now==NULL) return 0;
    if(now->num == target){
        return now->id;
    }

    if(now->num < target){
        if(now->right==NULL) return 0;
        return search(now->right, target);
    }

    if(now->num > target){
        if(now->left==NULL) return 0;
        return search(now->left, target);

    }
    return 0;
}


void freeBST(Node *root){
    if(root == NULL) return;
    if(root->left == NULL && root->right == NULL){
        free(root);
    }
    free(root->left);
    free(root->right);
}


int lst[MAX+1];
int n, q;
int main() {
    while (scanf("%d %d", &n, &q) == 2 ) {  
        for (int i = 1; i <= n; i++) {  
            scanf("%d", &lst[i]);  
        }
        Node *root;
        build_tree(&root, lst, 1, n);




        while(q){
            int t;
            scanf("%d", &t);
            if(search(root, t) == 0) printf("Break your bridge!");
            else printf("%d",search(root, t));
            q--;
            
        }
        

        
    }

    return 0;
}