#include<bits/stdc++.h>
using namespace std;

const int MAXN = 105;

int n, m, s, visited[MAXN];
set<int> adj[MAXN];
vector<int> Path;

void inp(){
    cin >> n  >> m >> s;
    // for(int i = 1; i <= n; ++i){
    //     for(int j = 1; j <= n; ++j){
    //         int x; cin >> x;
    //         if(x) adj[i].insert(j);
    //     }
    // }
    for(int i = 1; i <= m; ++i){
        int x, y; cin >> x >> y;
        adj[x].insert(y);
    }
    memset(visited, 0, sizeof(visited));
}

void Hamilton(int u, int step){
    if(step == n){
        if(adj[u].find(s) != adj[u].end()){
            for(auto x : Path) cout << x << " ";
            cout << endl;
        }
        return;
    }
    for(auto v : adj[u]){
        if(!visited[v]){
            visited[v] = 1;
            Path.push_back(v);

            Hamilton(v, step + 1);

            visited[v] = 0;
            Path.pop_back();
        }
    }
}

int main(){
    inp();

    visited[s] = 1;
    Path.push_back(s);
    Hamilton(s, 1);
}