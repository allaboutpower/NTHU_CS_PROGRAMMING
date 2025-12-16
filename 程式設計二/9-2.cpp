#include<iostream>
#include<vector>
using namespace std;


int main() {
    int n;
    cin >> n;
    vector<vector<int>> adj(n+1);
    vector<int>visit(n+1, 0);
    int e;
    cin >> e;

    for(int i=0;i<e;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
    }
    int q;
    cin>>q;
    int curvis=0;
    while(q--){
        int s,t;
        cin>>s>>t;
        curvis++;
        bool canreach=false;
        vector<int> stk;
        stk.push_back(s);
        visit[s]=curvis;

        while(!stk.empty()&&!canreach){
            int u =stk.back();
            stk.pop_back();
            for(int v:adj[u]){
                if(visit[v]==curvis)continue;
                visit[v]=curvis;
                if(v==t){
                    canreach = true;
                    break;
                }
                stk.push_back(v);

            }
        }
        if(canreach){
            cout<<"True\n";
        }
        else{
            cout<<"False\n";
        }



    }


    return 0;
}
