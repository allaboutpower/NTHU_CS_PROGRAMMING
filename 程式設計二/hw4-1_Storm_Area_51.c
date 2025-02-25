#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

int x_val, y_val, z_val;


enum cal{
    NUM, VAR, OPER
};


//Node == struct _Node
typedef struct _Node{
    struct _Node *left, *right;
    int type;
    int value;
    char op;
} Node;

Node *new_node(int type, int val, char ch){ // num = 0, xyz = 1, +- = 2,
    Node *p = (Node *)malloc(sizeof(Node));
    p->right = p->left = NULL;
    p->type = type;
    p->value = val;
    p->op = ch;
    return p;   
}

Node *Buildtree(){
    char exp[101];
    scanf("%s", exp);
    Node *now = NULL;

    if('0' <= exp[0]  && exp[0] <= '9'){
        now = new_node(NUM, atoi(exp), '\0');
    }

    else if('x'<=exp[0] && exp[0] <='z'){
        now = new_node(VAR, '\0', exp[0]);
    }

    else {
        now = new_node(OPER, '\0', exp[0]);
        now->left = Buildtree();
        now->right = Buildtree();
    }
    return now;
}

int show_inorder(Node *root){
    if(root == NULL) return 0;
    

    switch (root->type)
    {
        case NUM:
            printf("%d", root->value);
            return root->value;

        case VAR:
            printf("%c", root->op);
            switch (root->op)
            {
            case 'x':
                return x_val;
            case 'y':
                return y_val;
            case 'z':
                return z_val;
            
            
            }
        case OPER:{
            int l , r;
            l = show_inorder(root->left);
            printf("%c", root->op);
            r = show_inorder(root->right);
            switch(root->op){
                case '+':
                    return l+r;
                case '-':
                    return l-r;
                case '*':
                    return l*r;
                case '/':
                    return l/r;
            }
        }
    }
}

/*
/ + x * 3 y 4
3 1 9

*/
int main(){

    Node *root = Buildtree();
    scanf("%d%d%d", &x_val, &y_val, &z_val);
    printf("\n%d\n", show_inorder(root));


}