#include<bits/stdc++.h>
using namespace std;

const int MAXN = 105;

int n, s;
set<int> adj[MAXN];

void inp(){
    cin >> n >> s;
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= n; ++j){
            int x; cin >> x;
            if(x) adj[i].insert(j);
        }
    }
}

void Hierholzer(){
    stack<int> st;
    vector<int> Path;

    st.push(s);

    while(!st.empty()){
        int u = st.top();
        if(adj[u].size() != 0){
            int v = *adj[u].begin();
            st.push(v);

            adj[u].erase(v);
            adj[v].erase(u);
        }
        else {
            st.pop();
            Path.push_back(u);
        }
    }

    reverse(Path.begin(), Path.end());
    for(auto x : Path) cout << x << " ";
}

int main(){
    inp();
    Hierholzer();
}