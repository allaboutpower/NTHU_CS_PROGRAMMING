#include<stdio.h>
#include<stdlib.h>


int main(){
    double x, y, ans;
    int z ;
    scanf("%lf%lf%d", &x,&y,&z);
    printf("%.*f\n", z ,x*y);
    return 0;
}