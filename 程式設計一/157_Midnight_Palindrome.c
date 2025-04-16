#include<stdio.h>
#include<string.h>
char str[2001];

int count_odd(int ctr1, int ctr2, int l){
    int k=0;
    while((ctr1 >= 0 && ctr2 <l)&&(str[ctr1] == str[ctr2])){
		k++;
        ctr1--;
        ctr2++;
    }
    return k;
}

int count_even(int ctr1, int ctr2, int l){
    //printf("ctr1=%d ctr2=%d\n", ctr1 , ctr2);
    int k=0;
    while((ctr1 >= 0 && ctr2 <l)&&(str[ctr1] == str[ctr2])){
        k++;
        ctr1--;
        ctr2++;
    }
    return k;
}

void solve(){
    scanf("%s", &str);
    int l = strlen(str);
    int odd_ans = 0;
    for(int i=0; i<l; i++){
        odd_ans += count_odd(i, i, l);
    }
    int even_ans=0;
    for(int i=0; i<l-1; i++){
        even_ans += count_even(i, i+1, l);
    }
    printf("%d\n", odd_ans+even_ans);
}



int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        solve();
    }
    return 0;
    
}