#include<stdio.h>
#include<string.h>

int num[20000+1];

int find_factor(int x){
    int count=0;
    for(int i=1; i<=x; i++){
        if(x%i==0)count++;
    }
    return count;
}

void solve(){
    int l,r;
    scanf("%d%d", &l, &r);
    memset(num, 0, sizeof(num));
    for(int i=l; i<=r; i++){
        num[i]=find_factor(i);
        //printf("num[%d]=%d\n",i ,num[i]);
    }
    //printf("$%d\n", num[6]);
    int ans=0;
    int ans_idx=0;
    for(int i=r; i>=l;i--){
        
        if(num[i]>=ans){
            ans_idx = i;
            ans = num[i];
        }
    }
    printf("%d\n", ans_idx);
}


int main(){
    int T;
    scanf("%d", &T);
    while(T--){
        solve();
    }
    return 0;
}