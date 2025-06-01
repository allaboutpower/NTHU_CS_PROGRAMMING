#include<stdio.h>
#include<string.h>
#define max(a, b) ((a) > (b) ? (a) : (b))
#define min(a, b) ((a) < (b) ? (a) : (b))
#define rep(i, a, b) for(int i=a;i<b;i++)
int p[100001];




void solve(){
    memset(p, 0,sizeof(p) );
    int A,B,C,D;
    scanf("%d%d%d%d", &A,&B,&C,&D); 

    for(int x=A; x<=B; x++){
        p[x+B] += 1;
        p[x+C+1] -= 1;
    }

    for(int i=A+B; i<=B+C; i++){
        p[i]=p[i-1];
    }
    long long ans=0;
    for(int xy=A+B; xy<=B+C; xy++){
        int num_of_valid_z = max(0, min(D,xy)-C+1);
        ans+= p[i]*num_of_valid_z;
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