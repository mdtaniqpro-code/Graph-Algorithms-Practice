#include <bits/stdc++.h>
using namespace std;

vector<int> adj_list[1005];

void dfs(int src){
    vector<int> v;
    for(int x:adj_list[src]){
        v.push_back(x);
    }
    if(v.empty()){
        cout << -1 << endl;
        return;
    }
    sort(v.begin(),v.end(),greater<int>());
    for(int x:v) cout << x << " ";
    cout << endl;
}

int main() {
    int node,edge;
    cin>>node>>edge;
    while (edge--)
    {
        int a, b;
        cin >> a >> b;
        adj_list[a].push_back(b);
        adj_list[b].push_back(a);
    }

    int t; 
    cin >> t; 
    while (t--) {
        int a;
        cin >> a ;
        dfs(a);
    }
    return 0;
}
