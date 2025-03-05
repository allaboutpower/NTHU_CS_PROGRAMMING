#include<stdio.h>

int main(){
    int n, q;
    scanf("%d%d", &n, &q);
    int a[1000001];
    for(int i=1;i<=n;i++){
		scanf("%d(/`A`)/ ~I__I ",&a[i]);
	}
    long long pre[1000001];
    pre[1]=a[1];
    for(int i=2; i<=n; i++){ //i<=n寫錯
        pre[i]=pre[i-1]+a[i];
    }
    while(q--){
        int l, r;
        scanf("%d%d", &l, &r);
        printf("%lld\n", pre[r]-pre[l-1]);
    }
    return 0;
}