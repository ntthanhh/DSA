//SỐ FIBONACCI THỨ N

// Dãy số Fibonacci được xác định bằng công thức như sau:
// F[0] = 0, F[1] = 1;
// F[n] = F[n-1] + F[n-2] với mọi n >= 2.
// Các phần tử đầu tiên của dãy số là 0, 1, 1, 2, 3, 5, 8, ...
// Nhiệm vụ của bạn là hãy xác định số Fibonaci thứ n. Do đáp số có thể rất lớn, in ra kết quả theo modulo 10^9+7.

// Input:
// Dòng đầu tiên là số lượng bộ test T (T ≤ 1000).
// Mỗi test bắt gồm một số nguyên N (1 ≤ N ≤ 109).

// Output: 
// Với mỗi test, in ra đáp án trên một dòng.


// Input:              Output
// 3
// 2                   1
// 6                   8
// 20                  6765

#include<bits/stdc++.h>
using namespace std;

#define ll long long

const ll MOD = 1000000007;

struct Matrix{
    ll a[2][2];

    friend Matrix operator * (Matrix x, Matrix y){
        Matrix res;

        for(int i = 0; i < 2; ++i){
            for(int j = 0; j < 2; ++j){
                res.a[i][j] = 0;
                for(int k = 0; k < 2; ++k){
                    res.a[i][j] += x.a[i][k] * y.a[k][j];
                    res.a[i][j] %= MOD;
                }
            }
        }

        return res;
    }
};


Matrix Binpow(Matrix x, int k){
    if(k == 1) return x;
    Matrix a = Binpow(x, k / 2);
    if(k % 2 == 0) return a * a;
    return a * a * x;
}

int main(){
    Matrix x;
    x.a[0][0] = 1;
    x.a[0][1] = 1;
    x.a[1][0] = 1;
    x.a[1][1] = 0;
    int t; cin >> t;
    while(t--){
        int n; cin >> n;

        Matrix res = Binpow(x, n);

        cout << res.a[0][1] << endl;
    }
}