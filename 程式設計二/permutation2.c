#include<stdio.h>

int output[12];
int a[22];
int n, k;
void permutation2(int idx, int cur){
    if(idx == k) {//print
        for(int i=0; i<k; i++){
            printf("%d ", output[i]);
            
        }
        printf("\n");
        return;
    }
    for(int i=cur; i<=n; i++){
        output[idx] = a[i];
        permutation2(idx+1,i+1);
    }

}

int main(){
    scanf("%d%d", &k,&n);//k=3 n=5
    for(int i=1; i<=n; i++){
        a[i] = i;
    }

    permutation2(0, 1);
    return 0;
}
