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
int n, a[MAXN], ok = 0;

bool check(){
	FOR(i, 1, n - 2){
		string s = "";
		FOR(j, i, i + 2){
			s += (a[j] + '0');
			if(s == "101") return false;
		}
	}
	return true;
}

void ktao(){
	FOR(i, 1, n) a[i] = 0;
}

void sinh(){
	int i = n;
	while(i >= 1 && a[i] == 1){
		a[i] = 0;
		--i;
	}
	if(i == 0) ok = 1;
	else a[i] = 1;
}

int main() { 
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    ktao();
    while(!ok){
		if(check()){
			FOR(i, 1, n) cout << a[i];
			cout << endl;
		}
    	sinh();
    }
    return 0;
}