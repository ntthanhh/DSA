#include<bits/stdc++.h>
using namespace std;

int n, m;
vector<int> adj[1005];
bool visited[1005];

void ktao(){
    cin >> n >> m;

    for(int i = 0; i < m; ++i){
        int x, y; cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    memset(visited, false, sizeof(visited));
}

void dfs(int u){
    cout << u << " ";
    visited[u] = true;

    for(auto v : adj[u]){
        if(!visited[v]){
            dfs(v);
        }
    }
}

int main(){
    ktao();
    dfs(1);
}