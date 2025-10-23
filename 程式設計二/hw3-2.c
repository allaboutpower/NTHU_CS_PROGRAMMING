#include<stdio.h>
#define MAXN 1000000


int arr[MAXN+1];
long long pre[MAXN+1];

int main(){
    int n,q;
    scanf("%d%d", &n,&q);
    for(int i=1; i<=n; i++){
        int tmp;
        scanf("%d", &tmp);
        if(tmp>0)arr[i] = tmp;
        else arr[i]=0;
    }
    for(int i=1; i<=n; i++){
        pre[i] = pre[i-1]+arr[i];
    }
    while(q--){
        int l,r,m;
        scanf("%d%d%d", &l, &r, &m);
        if(r-l+1>=m){
            printf("%lld\n", pre[l+m-1]-pre[l-1]);
        }
        else{
            printf("%lld\n", pre[r]-pre[l-1]);
        }
    }
    //printf("%lld\n", pre[4]);
    return 0;

}