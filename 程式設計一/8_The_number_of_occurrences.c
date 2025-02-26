#include<stdio.h>
#include<string.h>

int main(){
    char a[4];
    int n;
    int count;
    int ans;
    scanf("%s%d", a, &n);

    while(n--){
        char b[9];
        scanf("%s", b);
        for(int i=0; i<strlen(b)-1;i++){
            int tmp=0;
            for(int j=0;j<strlen(a); j++){
                if(a[j] == b[i+j]){
                    tmp++;
                }
                if(tmp == strlen(a)) count++;
            }
        }
        if(count > ans) ans = count;

    }
    
    printf("%d", ans);
    return 0;


}