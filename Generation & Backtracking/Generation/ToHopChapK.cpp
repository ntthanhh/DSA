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

const int MAXN = 25;
int n, k, a[MAXN], arr[MAXN], ok = 0, ans = 0, target;

void ktao(){
    FOR(i, 1, k) a[i] = i;
}

void sinh(){
    int i = k;
    while(i >= 1 && a[i] == n - k + i) i--;
    if(i == 0) ok = 1;
    else{
        a[i]++;
        FOR(j, i + 1, k) a[j] = a[j - 1] + 1;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> k;
    ktao();
    while(!ok){
        FOR(i, 1, k) cout << a[i] << " ";
        cout << endl;
    	sinh();
    }
    return 0;
}