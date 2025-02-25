#include<stdio.h>

int main(){

    int x, y, z;
    scanf("%d%d%d", &x,&y,&z);
    int tmp = (x+y+z)/2;
    printf("%d %d %d\n", tmp-y, tmp-z, tmp-x);
    return 0;
}