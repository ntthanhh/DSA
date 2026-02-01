//BẬC THANG

// Một chiếc cầu thang có N bậc. Mỗi bước, bạn được phép bước lên trên tối đa K bước. Hỏi có tất cả bao nhiêu cách bước để đi hết cầu thang? (Tổng số bước đúng bằng N).

// Input:
// Dòng đầu tiên là số lượng bộ test T (T ≤ 100).
// Mỗi test gồm hai số nguyên dương N và K(1 ≤ N ≤ 100000, 1 ≤ K ≤ 100).

// Output: 
// Với mỗi test, in ra đáp án tìm được trên một dòng theo modulo 109+7.


// Input           Output
// 2               
// 2 2             2
// 4 2             5

// Giải thích test 1: Có 2 cách đó là (1, 1) và (2).
// Giải thích test 2: 5 cách đó là: (1, 1, 1, 1), (1, 1, 2), (1, 2, 1), (2, 1, 1), (2, 2).

#include<bits/stdc++.h>
using namespace std;

#define ll long long

const ll MOD = 1e9+7;

int main(){
    int t; cin >> t;
    while(t--){
        int n, k; cin >> n >> k;

        vector<ll> dp(n + 1, 0);
        dp[0] = 1;
        dp[1] = 1;

        for(int i = 2; i <= n; ++i){
            for(int j = 1; j <= k; ++j){
                if(i < j) break;
                
                dp[i] += dp[i - j];
                dp[i] %= MOD;
            }
        }

        cout << dp[n] << endl;
    }
}