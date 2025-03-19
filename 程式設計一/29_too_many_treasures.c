#include<stdio.h>
#define MAX_N 1000000
int t[MAX_N+1];
long long pre[MAX_N+1];
int n;

void prefix(){
    if(t[1]>0)pre[1]=t[1];
    else pre[1]=0;
    for(int i=2; i<=n; i++){
        if(t[i]>0){
            pre[i]=pre[i-1] + t[i];
        }
        else pre[i]=pre[i-1];
    }
}

int main(){
    pre[0]=0;
    int q;
    scanf("%d%d", &n, &q);
    for(int i=1; i<=n; i++){
        scanf("%d", &t[i]);
    }
    prefix();
    while(q--){
        int l, r, m;
        scanf("%d %d %d", &l, &r, &m);
        if(r-l+1 == m){
            printf("%lld\n", pre[r]-pre[l-1]);
        }
        else printf("%lld\n", pre[l+m-1]-pre[l-1]);
    }
    return 0;
}