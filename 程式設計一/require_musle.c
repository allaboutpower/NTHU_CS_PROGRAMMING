#include<stdio.h>
int ans;
int a[4];

int count(int i){
    return (a[i]-a[i-1])/2+(a[i]-a[i-1])%2;   
}

void solve(){
    int n,m;
    scanf("%d%d", &n, &m);//n=3 m=2
    a[0]=0;
    for(int i=1; i<=n; i++){
        scanf("%d", &a[i]);
    }
    for(int i=1; i<=n; i++){
        ans+=count(i);
    }
    printf("%d\n", ans);
}

int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        solve();
    }
    return 0;

}