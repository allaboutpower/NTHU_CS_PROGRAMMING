#include<stdio.h>
#include<stdlib.h>
#define MAX_N 100000
int a[MAX_N+1];
//a = 1 1 2 5 5 6 7 7 7 tar=6

int cmp(const void *a, const void *b){
    int l = *(int*)a;
    int r = *(int*)b;
    if(l>r) return 1;
    else if(l<r) return -1;
    else return 0;
}

int UB(int l, int r, int tar){
    int mid = (l+r)/2;
    if(mid==l){
        return r;
    }
    if(a[mid]<tar){
        return UB(mid, r, tar);
    }
    else if(a[mid]==tar){
        if(a[mid+1]>tar)return mid+1;
        else return UB(mid, r, tar);
    }
    else if(a[mid]>tar){
        return UB(l, mid, tar);
    }
}

int LB(int l, int r, int tar){
    int mid=(l+r)/2;
    if(mid==l){
        if(a[l]==tar)return l;
        else return r;
    }
    if(a[mid]<tar){
        return LB(mid, r, tar);
    }
    else if(a[mid]==tar){
        if(a[mid-1]<tar){
            return mid;
        }
        else return LB(l, mid, tar);
    }
    else if(a[mid]>tar){
        return LB(l, mid, tar);
    }
}
 


int main(){
    int n;
    scanf("%d", &n);
    for(int i=0; i<n; i++){
        scanf("%d", &a[i]);
    }
    qsort(a, n, sizeof(int), cmp);
    int q;
    scanf("%d", &q);
    while (q--)
    {
        int x;
        scanf("%d", &x);
        printf("%d\n", UB(0, n, x)-LB(0, n, x));
    }
    return 0;
}