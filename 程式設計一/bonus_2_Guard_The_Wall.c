#include <stdio.h>
#include <string.h>

int diff[5001];
int pre_1[5001];
int pre_2[5001];
int sect[5001];
int l[5001];
int r[5001];
int n,q;

int loss(int i, int j){
    int i_l = l[i];
    int i_r = r[i];
    int j_l = l[j];
    int j_r = r[j];
    int res = pre_1[r[i]]-pre_1[l[i]-1]+pre_1[r[j]]-pre_1[l[j]-1];
    if(i_r<j_l||i_l>j_r){
        return res;
    }
    else if(i_r>=j_r&&i_l<=j_r){
        if(i_l<j_l){
            return res + pre_2[j_r]-pre_2[j_l-1];
        }
        else return res + pre_2[j_r]-pre_2[i_l-1];
    }
    else if(j_l<=i_r&&j_l>=i_l){
        if(j_r>i_r){
            return res + pre_2[i_r]-pre_2[j_l-1];
        }
        else return res + pre_2[j_r]-pre_2[j_l-1];
    }
}

void solve(){
    scanf("%d%d", &n, &q); 
    for(int i=1; i<q+1; i++){
        scanf("%d%d", &l[i], &r[i]);

    }
    memset(diff, 0, sizeof(diff));
    for (int i = 1; i < q+1; i++) {
        diff[l[i]] += 1;
        diff[r[i] + 1] -= 1;
    }
    //pre_1 算出sect
    sect[0]=0;
    memset(pre_1, 0, sizeof(pre_1));
    memset(pre_2, 0, sizeof(pre_2));
    for(int i=1; i<n+1; i++){
        sect[i]=sect[i-1]+diff[i];
        if(sect[i]==1){
            pre_1[i]=pre_1[i-1]+1;
        }
        else pre_1[i]=pre_1[i-1];
        if(sect[i]==2){
            pre_2[i]=pre_2[i-1]+1;
        }
        else pre_2[i]=pre_2[i-1];

    }
    int full=0;
    for(int i=0;i<n+1; i++){
        if(sect[i]>0)full++;
    }
    //printf("%d", full);
    int ans=0;
    for(int i=1;i<q;i++){
        for(int j=i+1; j<q;j++){
            if(full-loss(i,j)>ans){
                ans = full - loss(i,j);
            }
        }
    }
    
    printf("%d ", ans);
    
}

int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        solve();
    }
    return 0;
}