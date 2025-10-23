#include<stdio.h>
#include<string.h>

#define MAX_N 2000000
int arr[MAX_N+1];
long long pre[MAX_N+1];

int main(){
    int n,q;
    while(scanf("%d%d", &n,&q)!=EOF){
        for(int i=1; i<=n; i++){
            scanf("%d", &arr[i]);
        }
        pre[1] = arr[1];
        for(int i=2;i<=n; i++){
            pre[i]= pre[i-1]+arr[i];
        }

        int max_l=0;
        int max_r=0;
        long long maxvalue =0;

        while(q--){
            int l,r;
            scanf("%d%d", &l, &r);
            long long tmp=0;
            if(r>=l){
                tmp = pre[r]-pre[l-1];
            }
            else{
                tmp = pre[n]-pre[l-1]+pre[r];
            }
            if(tmp>maxvalue){
                maxvalue=tmp;
                max_l=l;
                max_r=r;
            }
        }

        printf("Max_range: (%d,%d); Value: %lld\n", max_l, max_r, maxvalue);
    }
    return 0;
}