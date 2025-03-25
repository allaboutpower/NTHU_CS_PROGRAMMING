#include<stdio.h>
#define MAX_N 200000
#define MAX_M 100000
int num[MAX_N+1];
int req[MAX_M+1];

int main(){
    int n, m;
    scanf("%d%d", &n,&m);
    for(int i=1; i<=n; i++){
        num[i]=i;
    }
    for(int i=1; i<=m;i++){
        scanf("%d", &req[i]);
    }
    for(int i=m; i>=1;i--){
        if(num[req[i]]!=0){
            num[req[i]]=0;
        }
        else{
            req[i]=0;
        }
    }
    for(int i=m; i>=1;i--){
        if(req[i]>0) printf("%d\n", req[i]);
    }
    for(int i=1; i<=n; i++){
        if(num[i]>0) printf("%d\n", num[i]);
    }
    return 0;
}
