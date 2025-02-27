#include<stdio.h>
#include<math.h>

int main(){
    int n, all=0, cap=0, buy=0;
    scanf("%d", &n);

    while(all < n){
        buy++;
        all++;
        cap++;
        if(cap == 3){
            all++;
            cap = 1;
        }
    
    }
    
    printf("%d\n", buy);
    return 0;

}