#include <bits/stdc++.h>
using namespace std;

vector<int> adj_list[1005];

void dfs(int src,int dst){
    int flag=1;
    for(int x:adj_list[src]){
        if(x==dst) {
            cout << "YES" << endl;
            flag=0;
            break;
        }
    }
    if(flag) cout << "NO" << endl;
}

int main() {
    int node,edge;
    cin>>node>>edge;
    while (edge--)
    {
        int a, b;
        cin >> a >> b;
        adj_list[a].push_back(b);
    }

    int t; 
    cin >> t; 
    while (t--) {
        int a, b;
        cin >> a >> b;
        dfs(a,b);
    }
    return 0;
}
