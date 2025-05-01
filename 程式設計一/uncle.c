#include<stdio.h>


long long fpw(long long x, long long y, long long m){
    if(y==0)return 1%m;
    if(y%2==1){
        return fpw(x,y/2,m)*fpw(x,y/2,m)%m*x%m;
    }
    else return fpw(x,y/2,m)*fpw(x,y/2,m)%m;

}

int main(){
    long long x,y,m;
    scanf("%lld%lld%lld", &x, &y, &m);
    printf("%lld", fpw(x%m, y, m));
    return 0;

}