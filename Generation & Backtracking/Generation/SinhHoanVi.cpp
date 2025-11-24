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
int n, k, a[MAXN], arr[MAXN], ok = 0, ans = 0;

void ktao(){
    FOR(i, 1, n) a[i] = i;
}

void sinh(){
    int i = n - 1;
    while(i >= 1 && a[i] > a[i + 1]) i--;
    if(i == 0) ok = 1;
    else{
        int j = n;
        while(a[i] > a[j]) j--;
        swap(a[i], a[j]);
        reverse(a + i + 1, a + n + 1);
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    ktao();
    while(!ok){
		FOR(i, 1, n) cout << a[i] << " ";
		cout << endl;
    	sinh();
    }
    return 0;
}