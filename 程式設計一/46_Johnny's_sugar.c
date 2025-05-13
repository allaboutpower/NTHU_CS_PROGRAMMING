#include<stdio.h>
int sugar[1001][1001];
int row_ans[1001];
int col_ans[1001];


int main(){
    int n;
    scanf("%d", &n);
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            scanf("%d", &sugar[i][j]);
        }
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(sugar[i][j]>row_ans[i])row_ans[i]=sugar[i][j];
        }
    }

    for(int i=0; i<n; i++){
        col_ans[i] = sugar[0][i];
        for(int j=0; j<n; j++){
            if(sugar[j][i]<col_ans[i])col_ans[i]=sugar[j][i];
        }
    }
    for(int i=0; i<n; i++){
        if(i==n-1)printf("%d\n", row_ans[i]);
        else printf("%d ", row_ans[i]);
    }
    for(int i=0; i<n; i++){
        if(i==n-1)printf("%d\n", col_ans[i]);
        else printf("%d ", col_ans[i]);
    }

    return 0;
}