#include <stdio.h>
#include<stdlib.h>
#define MAX_N 100000
#define rep(i, a, b) for(int i=a;i<b;i++)

typedef struct _interval
{
    double l;
    double r;
}Interval;

Interval LR[MAX_N];

int cmp(const void *a, const void *b){
    Interval *ia = (Interval *)a;
    Interval *ib = (Interval *)b;
    if(ia->l<ib->l) return -1;
    if(ia->l>ib->l) return 1;
    if(ia->r<ib->r) return -1;
    if(ia->r<ib->r) return 1;

}


void solve(){
    int n,q;
    scanf("%d%d", &n,&q);
    for (int i = 0; i < q; i++)
    {
        scanf("%lf%lf", &LR[i].l, &LR[i].r);
    }
    qsort(LR, q, sizeof(LR[0]), cmp);
    double tot=0, cur_l=0, cur_r=0;
    rep(i,0,q){
        if(cur_r<LR[i].l){
            tot += cur_r-cur_l;
            cur_l = LR[i].l;
            cur_r = LR[i].r;
        }
        else if(cur_r<LR[i].r){
            cur_r = LR[i].r;
        }
    }
    tot += cur_r-cur_l;
    printf("%.6lf\n", ((double)n-tot) / n);


}

int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        solve();
    }
}