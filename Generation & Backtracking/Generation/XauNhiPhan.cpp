#include <bits/stdc++.h>
using namespace std;

const int MAXN = 25;
int n, a[MAXN], ok = 0;

void ktao(){
	for(int i = 1; i <= n; ++i) a[i] = 0;
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
		for(int i = 1; i <= n; ++i) cout << a[i] << " ";
		cout << endl;
    	sinh();
    }
    return 0;
}