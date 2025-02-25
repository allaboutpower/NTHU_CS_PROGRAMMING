#include <stdio.h>
#include <stdlib.h>

typedef struct _NODE
{
    int number;
    struct _NODE *ptr_to_right_node;
    struct _NODE *ptr_to_left_node;
} Node;

int find_in_seq(int* in, int start, int end, int num){
    while(start <= end){
        if(in[start]==num){
            return start;
            break;
        }
        else start++;
        
    }
    return 0;
}



static int cur = 0;
Node* buildTree(int* Inorder, int* Preorder, int inorder_start, int inorder_end)//0,8
{  
    if(inorder_start > inorder_end) return NULL;

    Node *p = (Node*)calloc(1, sizeof(Node));

    p->number = Preorder[cur];  
    cur++;

    if(inorder_start < inorder_end){
        int idx = find_in_seq(Inorder,inorder_start, inorder_end, Preorder[cur-1] );
        p->ptr_to_left_node = buildTree(Inorder, Preorder, inorder_start, idx-1);
        p->ptr_to_right_node = buildTree(Inorder, Preorder, idx+1, inorder_end);
    }
    return p;
    
}

void showPostorder(Node* root)
{   

    if(root){
        showPostorder(root->ptr_to_left_node);
        showPostorder(root->ptr_to_right_node);
        printf("%d ", root->number);
    }
    else return;
}

void freeTree(Node *root)
{
    if (root == NULL) return;
    if(root != NULL){
        freeTree(root->ptr_to_left_node);
        freeTree(root->ptr_to_right_node);
        free(root);
    }
    cur = 0;
    
}



int n;
int main(void)
{
    int id = 1;
    while( scanf( "%d", &n ) == 1 )
    {
        int inorder[100], preorder[100];
        for( int i = 0; i < n; i++ )
            scanf( "%d", &inorder[i] );
        for( int i = 0; i < n; i++ )
            scanf( "%d", &preorder[i] );
        
        Node *root = buildTree( inorder, preorder, 0, n-1 );


        printf( "testcase%d: ", id++ );
        showPostorder( root );
        printf( "\n" );
        freeTree( root );
    }
    return 0;
}