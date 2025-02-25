#include <stdio.h>
#include <math.h>

void findans(int *a);

int main(){
    int a[4];
    for(int i=0; i<3; i++){
        scanf("%d", &a[i]);
    }
    findans(a);
    return 0;
} 


void findans(int *a){
    int tmp;

    if( a[0] + a[2] == a[1]*2){
        printf("%d %d\n", a[0]-a[1]+a[0], a[2]+a[1]-a[0] );
    }   
    else{
        printf("%d %d\n", a[0]/(a[1]/a[0]), a[2]*(a[1]/a[0]) );
    }
    return;
}