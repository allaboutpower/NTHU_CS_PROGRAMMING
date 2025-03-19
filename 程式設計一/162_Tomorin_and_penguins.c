#include<stdio.h>
#include<string.h>
#define MAX_N 100000

int p[MAX_N];
int bit[32];
int n;

int maxbit(int x){
    int ans = 0;
    while(x>0){
        x /= 2;
        ans++;
    }
    return ans;
}

void solve(){
    memset(bit, 0, sizeof(bit));
    scanf("%d", &n);
    for(int i=0; i<n;i++){
        scanf("%d", &p[i]);
    }
    for(int i=0; i<n;i++){
        ++bit[maxbit(p[i])];
    }
    long long ans = 0;
    for(int i=0; i<32;i++){
        ans = ans + (long long)bit[i]*(bit[i]-1)/2;
    }
    printf("%lld\n", ans);
}

int main(){
    int t;
    scanf("%d", &t);
    while(t--){solve();}
    return 0;
}