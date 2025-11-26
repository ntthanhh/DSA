#include <bits/stdc++.h>
using namespace std;

const int MAXN = 20; 
int n, a[MAXN], ok = 0;

void ktao(){
    for(int i = 1; i <= n; ++i) a[i] = 0;
}

void sinh(){
    int i = n;
    while(i >= 1 && a[i] == 1){
        a[i] = 0;
        i--;
    }
    if(i == 0) ok = 1;
    else {
        a[i] = 1;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    ktao();
    while(!ok){
        cout << a[1];
        for(int i = 2; i <= n; ++i){
            int gray = a[i] ^ a[i - 1];
            cout << gray;
        }
        cout << endl;
        sinh();
    }
    return 0;
}