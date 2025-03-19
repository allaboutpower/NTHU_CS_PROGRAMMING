#include<stdio.h>
#define MAX_N 200000

int n;
int arr[MAX_N+1];
int idx[MAX_N+1];

int main(){
    scanf("%d", &n);
    for(int i=1; i<=n; i++){
        scanf("%d", &arr[i]);
        idx[arr[i]]=i;
    }
    int eaten=0;
    for(int i=1; i<=n; i++){
        int tmp;
        scanf("%d", &tmp);
        if(idx[tmp]>eaten) {
            printf("%d ", idx[tmp]-eaten);
            eaten = idx[tmp];
        }
        else {
            printf("0 ");
        }
    }

    return 0;



}