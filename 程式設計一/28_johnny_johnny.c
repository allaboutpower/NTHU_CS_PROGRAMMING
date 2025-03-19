#include<stdio.h>
int ai[21];
int count = 0;
int idx=0;
int tmp=0;

void find(int x, int n, int k, int ai[]){ //x=0 n=5 k=3
    tmp = tmp + ai[idx];
    if(tmp == k) count++;
    find(x+1, n, k, ai);
}

int main(){
    int n, k;
    for(int i=0; i<n; i++){
        scanf("%d", &ai[i]);
    }
    find(0, n, k, ai);
    printf("%d", count );
    return 0; 

}