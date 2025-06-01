#include <stdio.h>
#include<stdlib.h>
#define rep(i, a, b) for(int i=a;i<b;i++)
#define MAX_N 300000
int n,p,k;
int num[MAX_N+1];
int ans[MAX_N+1];


int cmp(const void *a, const void *b){
    return (*(int *)a-*(int *)b);
}

void solve(){
    scanf("%d%d%d", &n,&p,&k);
    rep(i,1,n+1){
        scanf("%d",&num[i]);
    }
    qsort(num+1, n, sizeof(int), cmp);

    rep(i, 1, n+1){
        if(i<k){
            ans[i]=ans[i-1]+num[i];
        }
        else{
            ans[i]=ans[i-k]+num[i];
        }
    }
    int x=0;
    rep(i,1, n+1){
        if(ans[i]<=p){
            x=i;
        }
    }
    printf("%d\n", x);

}

int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        solve();
    }
    return 0;
}