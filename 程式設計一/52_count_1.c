#include<stdio.h>
#define Max 1000000

//count 沒有寫return

int count(int i, int s){//i =110 s=0
    while(i>0){
        if(i%10==1) s++;
        i=i/10;
    }
    return s;
}

int main(){
    int t;
    scanf("%d", &t);
    int pre[Max+1];
    pre[1]=1;
    for(int i=2; i<=Max; i++){
        pre[i] = pre[i-1]+ count(i, 0);
    }
    while(t--){
        int a,b;
        scanf("%d%d", &a, &b );
        printf("%d\n", pre[b]-pre[a-1]);
    }
    return 0;
}

