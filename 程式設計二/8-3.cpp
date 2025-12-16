#include<iostream>
#include<map>
#include<vector>
#include<string>
using namespace std;


int count_volel(const string &s){
    int cnt=0;
    for(auto c:s){
        if(c=='a'||c=='e'||c=='i'||c=='o'||c=='u'){
            cnt++;
        }
    }
    return cnt;
}

char last_volel(const string &s){
    char l='\0';
    for(auto c:s){
        if(c=='a'||c=='e'||c=='i'||c=='o'||c=='u'){
            l=c;
        }
    }
    return l;
}

map<int,map<char,vector<string>>> bucket;

int main(){
    int n;
    cin>>n;
    string s;
    for(int i=0;i<n;i++){
        cin>>s;
        bucket[count_volel(s)][last_volel(s)].push_back(s);
    }


    int comp=0;
    int uncomp=0;
    for(auto count:bucket){
        int tmp=0;
        for(auto last:count.second){
            comp += last.second.size()/2;
            tmp += last.second.size()%2;
        }
        uncomp += tmp/2;
    }

    int ans = min(comp, uncomp);
    if(comp-uncomp>=2){
        ans+=(comp-uncomp)/2;
    }
    cout << ans << endl;


}