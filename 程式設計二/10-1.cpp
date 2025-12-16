#include<iostream>
#include<string.h>
#include<stdlib.h>
using namespace std;


int a[2002][26];
int visited[2002];
int findabc[26];


void DFS(int now, int n){
    for(int i=0;i<26;i++){
        if(a[now][i]==1&&findabc[i]==0){
            findabc[i]=1;
            for(int j=0;j<n;j++){
                if(a[j][i]=1&&visited[j]==0){
                    visited[j]=1;
                    DFS(j,n);
                }
            }
        }
    }
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int n; 
        int count=0;
        cin >> n;
        char s[1001];
        for(int i=0;i<n;i++){
            cin >> s;   
            int len = strlen(s);
            for(int j=0;j<len;j++){
                a[i][s[j]-'a']=1;
            }
        }

        for(int i=0;i<n;i++){
            if(visited[i]==0){
                visited[i]=1;
                DFS(i,n);
                count++;
            }
        }
        cout << count<< endl;
        memset(a,0,sizeof(a));
        memset(visited, 0,sizeof(visited));
        memset(findabc, 0,sizeof(findabc));

    }
}