#include<stdio.h>
#include<string.h>

char a[21];
int k;
char output[11];

void permute_1(int len, int idx){
    if(idx==k){
        printf("%s\n", output);
        return;
    }
    for(int i=0; i<len;i++){
        output[idx] = a[i];
        permute_1(len, idx+1);
    }
}

int main(){
    scanf("%s", a);
    scanf("%d", &k);
    permute_1(strlen(a), 0);
    return 0;
}