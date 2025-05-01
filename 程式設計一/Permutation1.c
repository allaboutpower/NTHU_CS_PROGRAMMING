#include<stdio.h>
#include<string.h>
char input[21];
int k;

void recursive(int idx, char output[]){
    if(idx==k){
        printf("%s\n", output);
        return;
    }

    int len = strlen(input);
    for(int i=0; i<len; i++){
        output[idx]=input[i];
        recursive(idx+1, output);
    }
}

int main(){
    scanf("%s", input);
    scanf("%d", &k);
    char output[21];
    recursive(0,output);
    return 0;
}