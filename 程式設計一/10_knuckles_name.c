#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int a[2002][26];
int visit[2002];
int findabc[26];
void dfs(int now,int n){
	for(int i=0;i<26;i++){
		if(a[now][i]>0&&findabc[i]==0){
			findabc[i]=1;
            for(int j=0;j<n;j++){
                if(a[j][i]!=0&&visit[j]==0){
                    visit[j]=1;
                    dfs(j,n);
				}
			}
		}
	}
}
int main () {
	int t;
	
	scanf("%d",&t);
	while(t--){
		int n;
      	int count=0;
		scanf("%d",&n);
		for(int i=0;i<n;i++){
			char temp[1001];
			scanf("%s",temp);
			int len=strlen(temp);
			for(int j=0;j<len;j++){
				a[i][temp[j]-'a']++;
			}
		}
		for(int i=0;i<n;i++){
			if(visit[i]==0){
				visit[i]=1;
				dfs(i,n);
				count++;
			}
		}
		printf("%d\n",count);
		memset(a,0,sizeof(a));
		memset(visit,0,sizeof(visit));
		memset(findabc,0,sizeof(findabc));
	}



	return 0;
}