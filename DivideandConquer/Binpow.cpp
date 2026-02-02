//LŨY THỪA

// Cho số nguyên dương N và K. Hãy tính NK modulo 109+7.

// Input:
// Dòng đầu tiên là số lượng bộ test T (T ≤ 20).
// Mỗi test gồm 1 số nguyên N và K (1 ≤ N ≤ 1000, 1 ≤ K ≤ 109).

// Output: 
// Với mỗi test, in ra đáp án trên một dòng.

// Input:          Output
// 2               
// 2 3             8
// 4 2             16


#include<bits/stdc++.h>
using namespace std;

#define ll long long

const ll MOD = 1000000007;

ll Pow(ll n, ll k){
    if(k == 0) return 1;
    ll x = Pow(n, k / 2);
    if(k % 2 == 1) return x * x * n;
    return x * x;
}

ll Pow1(int n, int k){
    ll res = 1;
    while(k){
        if(k % 2 == 1) res *= n;
        k /= 2;
        n *= n; 
    }
    return res;
}

int main(){
    ll n, k; cin >> n >> k;
    cout << Pow(n, k) << endl;
}