#include<stdio.h>
#include<string.h>

int eq(char a[], char b[], int len){
    if(len%2==1){
        if(strncmp(a, b, len)==0){
            return 1;
        }
        else return 0;
    }
    else{
        return (eq(a, b, len/2)       && eq(a+len/2, b+len/2, len/2)) || 
               (eq(a+len/2, b, len/2) && eq(a, b+len/2, len/2)) ;
    }
}

int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        char a[1001], b[1001];
        scanf("%s%s", &a, &b);
        if(eq(a, b, strlen(a)) ){
            printf("YES\n");
        }
        else printf("NO\n");
    }
    return 0;
}