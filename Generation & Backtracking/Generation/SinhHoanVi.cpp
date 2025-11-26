#include <bits/stdc++.h>
using namespace std;

const int MAXN = 20;
int n, k, a[MAXN], arr[MAXN], ok = 0, ans = 0;

void ktao(){
    for(int i = 1; i <= n; ++i) a[i] = i;
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
		for(int i = 1; i <= n; ++i) cout << a[i] << " ";
		cout << endl;
    	sinh();
    }
    return 0;
}