#include<stdio.h>
#include<string.h>
#define MAX_X 1000000
#define MOD 1000000007
int x;
char num[MAX_X];


void solve(){
    scanf("%d", &x);
    scanf("%s", num);
    long long ans = strlen(num);
    int len = ans;
    for(int i=0; i<x && i<len; i++){
        if(len<x){
            int copy_len = len-i-1;
            for(int j=0; j<num[i]-'1'; j++){
                strncpy(num+len, num+i+1, copy_len );
                len += copy_len;
                ans += copy_len;
            }
            num[len] = '\n';
        }
        else{
            ans =( (i+1)+ (num[i]-'0')*(ans-i-1+ MOD))%MOD;
        }
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