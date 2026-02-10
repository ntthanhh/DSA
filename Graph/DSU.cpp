#include<bits/stdc++.h>
using namespace std;

int parent[1005], sz[1005];

void Init(int n){
    for(int i = 1; i <= n; ++i){
        parent[i] = i;
        sz[i] = 1;
    }
}

// int Find(int u){
//     while(u != parent[u]){
//         u = parent[u];
//     }
//     return u;
// }

int Find(int u){
    if(u == parent[u]) return u;
    return parent[u] = Find(parent[u]);
}

// bool Union(int x, int y){
//     x = Find(x);
//     y = Find(y);
//     if(x == y) return false;
//     if(x < y) parent[y] = x;
//     else parent[x] = y;
//     return true;
// }

void Union(int x, int y){
    x = Find(x);
    y = Find(y);
    if(x != y){
        if(sz[x] < sz[y]){
            parent[x] = y;
            sz[y] += sz[x];
        }
        else {
            parent[y] = x;
            sz[x] += sz[y];
        }
    }
}


int main(){
    int t; cin >> t;
    while(t--){
        int n, m; cin >> n >> m;

        bool ok = false;

        Init(n);

        for(int i = 0; i < m; ++i){
            int x, y; cin >> x >> y;
            Union(x, y);
        }

        

        if(!ok) cout << "NO" << endl;
        else cout << "YES" << endl;
        
    }
}