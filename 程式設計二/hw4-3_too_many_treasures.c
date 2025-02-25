#include <stdio.h>








void prefix(long long *pre,int *val, int n){
    int idx = 2;
    pre[1]=val[1];
    while (idx <= n){
        pre[idx]= pre[idx-1]+val[idx];
        idx++;
    }
    
    
    }

int main(){


    int n ,q;
    scanf("%d%d", &n, &q);

    int val[n+1];
    for(int i=1; i<=n; i++){
        int tmp;
        scanf("%d", &tmp);
        if(tmp>=0){
            val[i]=tmp;
        }
        else val[i] = 0;
    }


    long long pre[n+1];
    prefix(pre,val, n);
    while(q){

        int l, r, m;
        
        scanf("%d%d%d", &l, &r, &m);
    
        if(l>1)  printf("%lld\n", pre[l+m-1]-pre[l-1]);
        else printf("%lld\n", pre[l+m-1]);
        q--;
    }
    return 0;




}