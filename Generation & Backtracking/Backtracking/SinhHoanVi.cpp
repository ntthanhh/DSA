#include <bits/stdc++.h>
using namespace std;

const int MAXN = 15;
int n, k, a[MAXN], used[MAXN];

void ktao(){
    memset(used, 0, sizeof(used));
}

void in(){
    for(int i = 1; i <= n; ++i) cout << a[i] << " ";
}

void Try(int i){
    for(int j = 1; j <= n; j++){
        if(!used[j]){
            a[i] = j;
            used[j] = 1;
            if(i == n){
                in();
                cout << endl;
            }
            else Try(i + 1);
            used[j] = 0;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ktao();
    cin >> n;
    Try(1);
    return 0;
}


