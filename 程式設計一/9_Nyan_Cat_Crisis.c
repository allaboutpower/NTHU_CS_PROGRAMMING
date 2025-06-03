#include<stdio.h>
#include<string.h>
#define rep(i, a, b) for(int i=a;i<b;i++)
#define print(x) printf("%lld ", x)
#define MAX_N 1000
int n,r, k;

typedef struct _point
{
    int visit;
    int x;
    int y;
}newpoint;

newpoint point[MAX_N]={0};


int connect(int a, int b){
    int dx = point[a].x-point[b].x;
    int dy = point[a].y-point[b].y;
    if(dx*dx+dy*dy>r*r)return 0;
    else return 1;
}

int DFS(int now){
    int res=1;
    point[now].visit=1;
    rep(i,0,n){
        if(point[i].visit)continue;
        if(connect(now, i)==0)continue;
        res+=DFS(i);
    }
    return res;
}

void solve(){
    memset(point, 0, sizeof(point));
    scanf("%d%d%d", &n, &r, &k);
    rep(i,0,n){
        scanf("%d%d", &point[i].x, &point[i].y);
    }

    int less_k=0;
    int more_k=0;
    
    rep(i,0,n){
        if(point[i].visit==1)continue;
        if(DFS(i)<k)less_k++;
        else more_k++;
    }
    printf("%d %d\n",less_k, more_k);
}

int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        solve();
    }
    return 0;
    
}