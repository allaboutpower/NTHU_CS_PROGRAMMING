#include<stdio.h>
#include<stdlib.h>

typedef struct _NODE
{
    int number;
    struct _NODE *ptr_to_right_node;
    struct _NODE *ptr_to_left_node;
} Node;

int preorder_idx = 0;
Node* buildTree(int* Inorder, int* Preorder, int inorder_start, int inorder_end)
{
    if(inorder_start>inorder_end)return NULL;

    Node *nd = (Node*)malloc(sizeof(Node));
    nd->number=Preorder[preorder_idx];
    preorder_idx++;

    int inorder_idx;
    for(int i=inorder_start; i<=inorder_end; i++){
        if(Inorder[i]==nd->number){
            inorder_idx = i;
            break;
        }
    }

    nd->ptr_to_left_node = buildTree(Inorder, Preorder, inorder_start, inorder_idx-1);
    nd->ptr_to_right_node = buildTree(Inorder, Preorder, inorder_idx+1, inorder_end);
    return nd;
}
void showPostorder(Node* root)
{
    if(root){
        showPostorder(root->ptr_to_left_node);
        showPostorder(root->ptr_to_right_node);
        printf("%d ", root->number);
    }
   
}

void freeTree(Node *root)
{
    preorder_idx=0;
    if(root){
        freeTree(root->ptr_to_left_node);
        freeTree(root->ptr_to_right_node);
        free(root);
    }
    
}


int n;
int main(void)
{
    int id = 1;
    while( ~scanf( "%d", &n ) )
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