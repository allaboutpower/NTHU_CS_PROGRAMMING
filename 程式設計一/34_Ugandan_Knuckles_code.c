
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #define rep(i, a, b) for(int i=a;i<b;i++)
    #define MAX_N 1000
    #define MAX_S 1000
    char str[MAX_N][MAX_S+1];


    int cmp(const void *a, const void *b){
        char *sa= (char *)a;
        char *sb= (char *)b;
        size_t len_a = strlen(sa);
        size_t len_b = strlen(sb);
        return len_a-len_b;
    }

    int checkvaild(const char *substr,const char *str){
        size_t len_sub = strlen(substr);
        size_t len_str = strlen(str);
        rep(i,0,len_str-len_sub+1){
            if(strncmp(substr,str+i, len_sub)==0){
                return 1;
            }
        }
        return 0;
    }

    int main(){
        int n;
        scanf("%d", &n);
        rep(i,0,n){
            scanf("%s", str[i]);
        }
        qsort(str, n, sizeof(str[0]), cmp);
        int OK=1;
        rep(i,1,n){
            if(!checkvaild(str[i-1], str[i])){
                OK=0;
                break;
            }
        }
        if(OK){
            printf("YES\n");
            rep(i,0,n){
                printf("%s\n" , str[i]);
            }
        }
        else printf("NO\n");
        return 0;
    }