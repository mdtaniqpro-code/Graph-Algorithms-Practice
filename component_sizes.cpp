#include <bits/stdc++.h>
using namespace std;

int a, b;
char grid[1005][1005];
bool vis[1005][1005];
vector<pair<int,int>> v={{-1,0},{1,0},{0,-1},{0,1}};
int cnt;

bool valid(int i,int j){
    if(i<0 || i>=a || j<0 || j>=b){
        return false;
    }
    return true;
}

void dfs(int si,int sj){
     vis[si][sj]=true;
     cnt++;
    for(int i=0;i<4;i++){
        int ci=si+v[i].first;
        int cj=sj+v[i].second;
        if(valid(ci,cj)&&!vis[ci][cj]&&grid[ci][cj]!='#') 
            dfs(ci,cj);
    }
}

int main() {
    vector<int> ans;
    cin >> a >> b;

    for (int i = 0; i < a; i++) {
        for (int j = 0; j < b; j++) {
            cin>>grid[i][j];
        }
    }

    memset(vis,false,sizeof(vis));

    for (int i = 0; i < a; i++) {
        for (int j = 0; j < b; j++) {
            if(!vis[i][j] && grid[i][j]=='.'){
                cnt=0;
                dfs(i,j);
                ans.push_back(cnt);
            }
        }
    }

    sort(ans.begin(),ans.end());

    if(ans.empty()) cout << 0 << endl;
    else{
        for(int x:ans) cout << x << " ";
    }

    return 0;
}
