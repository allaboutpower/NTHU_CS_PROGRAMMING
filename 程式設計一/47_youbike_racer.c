#include <stdio.h>
#include<string.h>
#define rep(i, a, b) for(int i=a;i<b;i++)
#define scan(x) scanf("%d", &x)
#define print(x) printf("%d ", x)

int main(){
    int n,k;
    scanf("%d%d", &n,&k);

    int points[n+1];
    points[0]=0;
    int now=0;
    int bike=0;
    int flag=1;
    rep(i,1,n+1){
        scanf("%d", &points[i]);
        if(points[i]-points[i-1]>k){
            flag=0;
        }
        if(now+k<points[i]){
            now=points[i-1];
            bike++;
        }
    }
    if(flag){
        print(bike);
    }
    else printf("The Legend Falls.");
    return 0;
    
}