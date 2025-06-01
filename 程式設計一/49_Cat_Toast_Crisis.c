#include<stdio.h>
#define rep(i, a, b) for(int i=a;i<b;i++)
#define print(x) printf("%lld ", x)
#define MAX_N 1000
int n,r;

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

int main(){
    scanf("%d%d", &n, &r);
    rep(i,0,n){
        scanf("%d%d", &point[i].x, &point[i].y);
    }

    int sig=0;
    int mul=0;
    
    rep(i,0,n){
        if(point[i].visit==1)continue;
        if(DFS(i)==1)sig++;
        else mul++;
    }
    
    

    printf("%d %d\n",sig, mul);
    return 0;
}