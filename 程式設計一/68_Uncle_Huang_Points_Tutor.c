#include<stdio.h>

long long fpw(long long x, long long y, long long m){

    if(y==0){
        return 1%m;
    }

    long long a = fpw(x, y/2, m);
    if(y%2==0){
        return a*a%m;
    }
    else{
        return a*a%m * x%m;
    }
}

int main(){
    long long x, y ,m;
    scanf("%lld%lld%lld", &x, &y, &m);
    printf("%lld", fpw(x%m, y, m));
    return 0;
}