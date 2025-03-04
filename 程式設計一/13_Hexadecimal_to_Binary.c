#include<stdio.h>
#include<string.h>


void binary(int hex){
    if(hex==0){
       return;
    }
    else{
        binary(hex/2);
        printf("%d", hex%2);
    }
}


int main(){
    int X,Y;
    scanf("%x%x", &X,&Y);
    binary(X+Y);
    printf("\n");
  
    return 0;
}