#include<stdio.h>

int main(){
    float x;
    while(~scanf("%f", &x)){
        unsigned int B = *((unsigned int*)(&x));
        for(int i=31; i>=0; i--){
            printf("%d", B&(1<<i) ? 1 : 0);
        }
        puts("");
    }
    return 0;
}