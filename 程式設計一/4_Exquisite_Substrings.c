#include <stdio.h>
#include <string.h>

int main(){

    char str[2004];
    while(scanf("%s", str) != EOF ){
        int len = strlen(str);
        //printf("%d\n", len);
        long long count = 0;

        for(int i=0; i<len-1; i++){
            for(int j=i+1; j<len; j++){
                if(str[i] == str[j]){
                    count++;
                    for(int k=1; k<=(j-i)/2; k++){
                        if(str[i+k] != str[j-k]) {
                            count--;
                            break;}
                    }
                }
            }
        }
        printf("%lld\n", count);
    }
    return 0;
}