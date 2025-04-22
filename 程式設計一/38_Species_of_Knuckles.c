#include<stdio.h>

int main(){
    char s[26]={0};
    int n;
    scanf("%d", &n);
    for(int i=0 ;i<n; i++){
        char tmp;
        scanf("%c", &tmp);
        s[tmp-'a']++;
    }
	if(n==1) {
        printf("I'm the god of Knuckles!");
        return 0;
    }
    for(int i=0 ;i<n; i++){
        if(s[i]>=2) {
            printf("I'm the god of Knuckles!");
            return 0;
        }
    }
    printf("Different makes perfect");
    return 0;
}