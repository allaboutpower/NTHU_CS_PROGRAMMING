#include<stdio.h>

int main(){
    char str[7];
    scanf("%s", str);
    float ans;

    ans = (str[0]-'0')*101+(str[1]-'0')*20+(str[2]-'0')*101+(str[4]-'0')*0.101+(str[5]-'0')*0.02+(str[6]-'0')*0.101;

    printf("%.3f\n",ans);
    return 0;

}