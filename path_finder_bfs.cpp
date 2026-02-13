#include <bits/stdc++.h>
using namespace std;

char grid[1005][1005];
bool vis[1005][1005];
int dst[1005][1005];
int a, b;

vector<pair<int,int>> mover={{-1,0},{1,0},{0,-1},{0,1}};

bool valid(int i,int j){
    if(i<0||i>=a||j<0||j>=b) return false;
    return true;
}

void bfs(int si,int sj){
    vis[si][sj]=true;
    dst[si][sj]=0;
    queue<pair<int,int>> q;
    q.push({si,sj});
    while (!q.empty())
    {
        pair<int,int> par=q.front();
        q.pop();

        int par_i=par.first;
        int par_j=par.second;

        for (int i = 0; i < 4; i++) {
            int ci=par_i+mover[i].first;
            int cj=par_j+mover[i].second;
            if(valid(ci,cj)&&!vis[ci][cj]&&grid[ci][cj]!='#') {
                q.push({ci,cj});
                vis[ci][cj]=true;
                dst[ci][cj]=dst[par_i][par_j]+1;
            }
        }
    }
}

int main() {
    cin >> a >> b;
    int si=-1,sj=-1,di=-1,dj=-1;

    for (int i = 0; i < a; i++) {
        for (int j = 0; j < b; j++) {
            cin>>grid[i][j];
            if(grid[i][j]=='A') {
                si=i;sj=j;
            }
            if(grid[i][j]=='B') {
                di=i;dj=j;
            }
        }
    }

    if(si<0||di<0) {
        cout << "NO" << endl;
        return 0;
    }

    memset(vis,false,sizeof(vis));
    memset(dst,-1,sizeof(dst));

    bfs(si,sj);

    if(dst[di][dj]==-1) cout << "NO" << endl;
    else cout << "YES" << endl;

    return 0;
}
