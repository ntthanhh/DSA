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
int n, k, a[MAXN], arr[MAXN], ok = 0, ans = 1;

void sinh(){
    int i = ans;
    int Sum = 0;
    while(i >= 1 && a[i] == 1){
        i--;
        Sum++;
    }
    if(i == 0) ok = 1;
    else{
        a[i]--;
        Sum++;
        int x = a[i];
        while(Sum >= x){
            i++;
            a[i] = x;
            Sum -= x;
        }
        if(Sum > 0){
            i++;
            a[i] = Sum;
        }
        ans = i;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    a[1] = n;
    while(!ok){
		FOR(i, 1, ans) cout << a[i] << " ";
		cout << endl;
    	sinh();
    }
    return 0;
}