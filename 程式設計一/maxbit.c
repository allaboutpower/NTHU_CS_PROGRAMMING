#include<stdio.h>
#include<string.h>
#define MAX_N 100000
int num[MAX_N+1];
int bit[32];

int maxbit(int n){
    int a=0;
    while(n>0){
        n/=2;
        a++;
    }
    return a;
}

void solve(){
    memset(bit, 0, sizeof(bit));
    long long ans=0;
    int n;
    scanf("%d", &n);
    for(int i=0; i<n; i++){
        int tmp;
        scanf("%d", &tmp);
        bit[maxbit(tmp)]++;
        num[i]=tmp;
    }
    for(int i=0; i<=32; i++){
        ans+=(long long)bit[i]*(bit[i]-1)/2;
    }
    printf("%lld\n", ans);

}

int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        solve();
    }
    return 0;
}