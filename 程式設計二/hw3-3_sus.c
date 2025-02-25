#include<stdio.h>


/*

9
5 3 2 1 4 7 6 8 9
1 2 4 3 6 9 8 7 5
9
2 7 3 6 8 1 5 9 4
3 8 1 6 7 4 9 5 2

*/


int main(){

    int n;
    
    int pre[9], post[9]; 
    while(scanf("%d", &n)==1 ){
        
        long long ans = 1;
        for(int i=0; i<n; i++){
            scanf("%d", &pre[i]);    
        }

        for(int j=0; j<n; j++){
            scanf("%d", &post[j]);
        }

        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(pre[i]==post[j+1] && pre[i+1]==post[j]){
                    ans *= 2;
                }
                
            }
        }
        printf("%lld\n", ans);

    }
    return 0;

}