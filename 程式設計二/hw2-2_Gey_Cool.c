#include<stdio.h>
#include<stddef.h>
#define max 2000000

int ar[max+1];
long long pre[max+1];

void prefix_sum(int n){

    pre[1]=ar[1];
    int i = 2;
    while (i<=n){
        pre[i]= pre[i-1]+ar[i];
        i++;
    }
}

int main(){
    
    int n, q;
    int max_r1=0, max_r2=0; 
    long long value = 0;    


	
    while (scanf("%d%d", &n, &q) != EOF ){
        value = 0;
        for(int i=1; i<=n; i++){
            scanf("%d", &ar[i]);
        }
        prefix_sum(n); //建立前墜和
    
    
        while(q){    //比較
            int b1, b2;
            scanf("%d%d",&b1, &b2 );
    
            if(b1<b2 ){
                if(value < pre[b2]-pre[b1-1]){
                    value = pre[b2]-pre[b1-1];
                    max_r1 = b1;
                    max_r2 = b2;
                    //printf("%d %d\n", max_r1, max_r2);
                }
            }
            else if(b1==b2){
                if(value < pre[b2]-pre[b2-1]){
                    value = pre[b2]-pre[b2-1];
                    max_r1 = b1;
                    max_r2 = b2;
                    //printf("%d %d\n", max_r1, max_r2);
                }
            }
            else if(b1>b2){
                if(value < pre[n]-pre[b1-1]+pre[b2]){
                    value = pre[n]-pre[b1-1]+pre[b2];
                    max_r1 = b1;
                    max_r2 = b2;
                    //printf("%d %d\n", max_r1, max_r2);
                }
            }
            q--;
        }
    printf("Max_range: (%d,%d); Value: %lld\n", max_r1, max_r2, value);
    }
	return 0; 
}