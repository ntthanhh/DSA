#include<bits/stdc++.h>
using namespace std;

const int MAXN = 105;

int n, cnt, col[MAXN], d1[MAXN], d2[MAXN];

void Try(int i){
    for(int j = 1; j <= n; ++j){
        if(!col[j] && !d1[i - j + n] && !d2[i + j - 1]){
            col[j] = d1[i - j + n] = d2[i + j - 1] = 1;

            if(i == n) ++cnt;
            else Try(i + 1);

            col[j] = d1[i - j + n] = d2[i + j - 1] = 0;
        }
    }
}

int main(){
    int t; cin >> t;
    while(t--){
        cin >> n;

        memset(col, 0, sizeof(col));
        memset(d1, 0, sizeof(d1));
        memset(d2, 0, sizeof(d2));

        cnt = 0;
        Try(1);

        cout << cnt << endl;
    }
}