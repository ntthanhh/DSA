#include <bits/stdc++.h>
using namespace std;

const int MAXN = 15;
int n, k, a[MAXN], used[MAXN];

void in(){
    for(int i = 1; i <= k; ++i) cout << a[i] << " ";
}

void Try(int i){
    for(int j = a[i - 1] + 1; j <= n - k + i; j++){
        a[i] = j;
        if(i == k){
            in();
            cout << endl;
        }
        else Try(i + 1);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    a[0] = 0;
    cin >> n >> k;
    Try(1);
    return 0;
}


