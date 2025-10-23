#include<stdio.h>
#define rep(i,a,b) for(int i=a; i<b; i++)

int post[9];
int pre[9];

int main(){
    int n;
    while(scanf("%d", &n)==1){
        rep(i,0,n){
            scanf("%d", &pre[i]);
        }
        rep(i,0,n){
            scanf("%d", &post[i]);
        }
        long long ans=1;
        rep(i,0,n){
            rep(j,0,n){
                if(pre[i]==post[j+1]&&pre[i+1]==post[j]){
                    ans*=2;
                }

            }
        }
        printf("%lld\n", ans);
    }
    return 0;
}