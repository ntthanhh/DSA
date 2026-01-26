#include <bits/stdc++.h>
using namespace std;

const int MAXN = 15;
int n, a[MAXN];

void ktao(){
    for(int i = 1; i <= n; ++i) a[i] = 0;
}

void in(){
    for(int i = 1; i <= n; ++i) cout << a[i] << " ";
}

void Try(int i){
    for(int j = 0; j <= 1; j++){
        a[i] = j;
        if(i  == n){
            in();
            cout << endl;
        }
        else Try(i + 1);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    ktao();
    Try(1);
    return 0;
}

