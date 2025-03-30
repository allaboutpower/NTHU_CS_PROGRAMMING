#include<stdio.h>
#include<string.h>

int rec[26];
int arr[26];
int idx[26];

int check(int idx, int num){//idx 25 num 9 
    int count = 0;
    for(int i=1+5*((idx-1)/5); i<=5+5*((idx-1)/5); i++){
        if(rec[i]==1) count++;
    }
    
    if(count==5) return num;
    count = 0;
    for(int i=0; i<5; i++){
        if(rec[(idx-(idx/5)*5) + i*5]==1) count++;
    }

    if(count==5) return num;
    count = 0;
    if(idx==1||idx==7||idx==13||idx==19||idx==25){
        if(rec[1]==1)count++;
        if(rec[7]==1)count++;
        if(rec[13]==1)count++;
        if(rec[19]==1)count++;
        if(rec[25]==1)count++;
    }
    if(count==5) return num;
    count = 0;
    if(idx==13||idx==5||idx==9||idx==17||idx==21){
        if(rec[5]==1)count++;
        if(rec[9]==1)count++;
        if(rec[13]==1)count++;
        if(rec[17]==1)count++;
        if(rec[21]==1)count++;
    }
    if(count==5) return num;
    return 0;
}

int main(){
    for(int i=1; i<=25; i++){
        scanf("%d", &arr[i]);
        idx[arr[i]] = i;
    }

    int t;
    scanf("%d", &t);
    for(int i=1; i<=t; i++){
        memset(rec, 0, sizeof(rec));
        int n=0;
        int x=0;
        scanf("%d", &n);
        for(int i=1; i<=n; i++){
            int tmp;
            scanf("%d", &tmp);
            rec[idx[tmp]]++;
            if(x==0) x = check(idx[tmp], i);
            //printf("rec[10] = %d\n", rec[20]);
        }
        if(x==0)printf("Case #%d: Not yet \\(^o^)/\n", i);
        else printf("Case #%d: %d\n", i, x);
    }
    
    return 0;
}