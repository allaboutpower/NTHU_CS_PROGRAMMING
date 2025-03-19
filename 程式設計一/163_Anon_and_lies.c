#include<stdio.h>
#include<string.h>
#define MAX_N 10000000
#define MAC_A 1000000000

int main(){
    int T;
    scanf("%d", &T);
    while(T--){
        int num[MAX_N+1];
        memset(num, 0, sizeof(num));
        int n;
        scanf ("%d", &n);
        for(int i=0; i<n; i++){
            int tmp;
            scanf("%d", &tmp);
            
            if(num[tmp]==tmp){
                num[tmp]=0;
            }
            else {
                num[tmp]=tmp;
            }
            printf("%d", tmp);
        }
        for(int i=0; i<MAX_A; i++){
            if(num[i]!=0)printf("%d\n", num[i]);
            
        }
        
    }
    return 0;
}