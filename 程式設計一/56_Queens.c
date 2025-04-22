#include<stdio.h>
int board[14][14];
int n;
int ans=0;
//兩個int n
int queenok(int row, int col){
    if(board[row][col]==0)return 1;
    return 0;
}

void placeorremove(int row, int col, int diff){
    for(int i=0; i<n; i++) board[i][col]+=diff;
    for(int j=0; row+j<n && col+j<n; j++) board[row+j][col+j]+=diff;
    for(int j=0; row+j<n && col-j>=0; j++) board[row+j][col-j]+=diff;
}

void solve_Queen(int row){
    if(row == n) {
        ans++;
        return;
    }
    for(int j=0; j<n; j++){
        if(queenok(row, j)){
            placeorremove(row, j, 1);
            solve_Queen(row+1);
            placeorremove(row, j, -1);
        }
    }

}

int main(){
    scanf("%d", &n);
    solve_Queen(0);
    printf("%d", ans);
}