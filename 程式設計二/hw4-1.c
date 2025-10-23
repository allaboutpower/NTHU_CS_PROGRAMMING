#include<stdio.h>

int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        long long x;
        scanf("%lld", &x);

        long long num=10;
        while((num/10)<=x){
            int digit = (x%num) / (num/10);
            if(digit>=5){
                x = x+(num-x%num);
            }
            num*=10;
        }

        printf("%lld\n", x);
    }
    return 0;

}