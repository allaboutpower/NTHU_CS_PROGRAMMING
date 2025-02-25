#include<stdio.h>
#include<stdlib.h>

typedef struct data{
    int admin, license, index;
}st;

int cmp(const void *a, const void *b) {
    st x = *(st *)a;
    st y = *(st *)b;
    if(x.admin != y.admin){
        return x.admin - y.admin;
    }
    else{
        if(x.license == y.license){
            return x.index - y.index;
        }
        else{
            return x.license - y.license;
        }
    }
}

st data[100001];
int main(){
    int n, a, l;
    scanf("%d", &n);
    for(int i=0; i<n; i++){
        scanf("%d%d", &data[i].admin, &data[i].license);
        data[i].index = i+1;
    }
    qsort(data,n,sizeof(st),cmp);
    for(int i=0; i<n; i++){
        printf("%d ", data[i].index);
    }
    return 0;
    
}