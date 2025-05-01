#include<stdio.h>
#define size n+m
int board[14][14];
int n, m;
int ans=0;
//兩個int n
int queenok(int row, int col){
    if(board[row][col]==0)return 1;
    return 0;
}

void placeorremove(int row, int col, int diff, int isqueen){
    for(int i=0; i<n; i++) board[i][col]+=diff;
    if(isqueen){
        for(int j=0; row+j<n && col+j<n; j++) board[row+j][col+j]+=diff;
        for(int j=0; row+j<n && col-j>=0; j++) board[row+j][col-j]+=diff;
    }
    
}

void solve_Queen(int row, int qcnt, int rcnt){
    if(row == n) {
        if(qcnt==n&&rcnt==m){
            ans++;
            return;
        }
    }
    for(int j=0; j<size; j++){
        if(queenok(row, j)){
            if(qcnt<n){
                placeorremove(row, j, 1, 1);
                solve_Queen(row+1, qcnt+1, rcnt);
                placeorremove(row, j, -1, 1);
            }
            if(rcnt<m){
                placeorremove(row, j, 1, 0);
                solve_Queen(row+1, qcnt, rcnt+1);
                placeorremove(row, j, -1, 0);
            }
            
        }
    }

}

int main(){
    scanf("%d%d", &n, &m);
    solve_Queen(0, 0, 0);
    printf("%d", ans);
}