#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
typedef pair<int, pair<int, int>> piii;

#define FOR(i, a, b) for (int i = (a); i <= (b); ++i)
#define FORd(i, a, b) for (int i = (a); i >= (b); --i)
#define fi first
#define se second
#define pb push_back
#define ll long long
#define mp make_pair

const int MAXN = 20; 
int n, a[MAXN], ok = 0;

void ktao(){
    FOR(i, 1, n) a[i] = 0;
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
        FOR(i, 2, n){
            int gray = a[i] ^ a[i - 1];
            cout << gray;
        }
        cout << endl;
        sinh();
    }
    return 0;
}