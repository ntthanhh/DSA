//DÃY CON CHUNG

// Cho dãy số A[], B[] và C[] là dãy không giảm và có lần lượt N, M, K phần tử. Nhiệm vụ của bạn là hãy tìm các phần tử chung của 3 dãy số này.

// Input:
// Dòng đầu tiên là số lượng bộ test T (T ≤ 20).
// Mỗi test gồm số nguyên N, M và K (1≤ N, M, K ≤ 100 000).
// Dòng tiếp theo gồm N số nguyên A[i], rồi M số nguyên B[i] và K số nguyên C[i].
// (0 ≤ A[i], B[i], C[i] ≤ 10^9).

// Output: 
// Với mỗi test, in ra trên một dòng là đáp án thu được. Nếu không tìm được đáp án, in ra “NO”.


// Input:                          Output
// 3
// 6 5 8                           20 80
// 1 5 10 20 40 80
// 5 7 20 80 100
// 3 4 15 20 30 70 80 120
// 3 5 4                           5 5
// 1 5 5
// 3 4 5 5 10
// 5 5 10 20
// 3 3 3                           NO
// 1 2 3
// 4 5 6
// 7 8 9

#include<bits/stdc++.h>
using namespace std;

int main(){
    int t; cin >> t;
    while(t--){
        int n, m, k; cin >> n >> m >> k;

        vector<int> a(n), b(m), c(k);
        for(auto &x : a) cin >> x;
        for(auto &x : b) cin >> x;
        for(auto &x : c) cin >> x;

        bool ok = 0;
        int x = 0, y = 0, z = 0;
        while(x < n && y < m && z < k){
            if(a[x] == b[y] && b[y] == c[z]){
                ok = 1;
                cout << a[x] << " ";
                ++x; ++y; ++z;
            }
            else {
                int Min = min({a[x], b[y], c[z]});
                if(a[x] == Min) ++x;
                if(b[y] == Min) ++y;
                if(c[z] == Min) ++z;
            }
        }

        if(!ok) cout << "NO";
        cout << endl;
    }
}