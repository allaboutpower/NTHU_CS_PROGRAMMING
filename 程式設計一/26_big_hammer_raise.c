#include<stdio.h>   

int main(){
    double a,b;
    double ans;
    scanf("%lf%lf", &a, &b);
    ans = a;
    ans = ans*b;

    printf("%.4lf\n", ans);
    return 0;

}