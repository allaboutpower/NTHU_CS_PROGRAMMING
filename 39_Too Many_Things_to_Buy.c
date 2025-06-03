#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAX_N 100000

typedef struct _prod
{
    int a,b;
}Prod;
Prod p[MAX_N+1];

int cmp(const void *a, const void *b){
    Prod pa = *(Prod*)a;
    Prod pb = *(Prod*)b;
    int da=pa.a-pa.b;
    int db=pb.a-pb.b;
    if(db<da)return 1;
    else if(da<db) return -1;
    else return 0;
}


int main(){
    int n,k;
    scanf("%d%d", &n,&k);
    for(int i=0; i<n; i++){
        scanf("%d", &p[i].a);
    }
    for(int i=0; i<n; i++){
        scanf("%d", &p[i].b);
    }
    qsort(p, n, sizeof(Prod), cmp);
    long long sum=0;
    int i=0;
    for(; i<k; i++){
        sum+=p[i].a;
    }
    for(; i<n &&p[i].a<p[i].b; i++){
		sum+=p[i].a;
    }
    for(; i<n; i++){
        sum+=p[i].b;
    }
    printf("%lld\n", sum);
    return 0;


}