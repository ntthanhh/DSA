//LŨY THỪA MA TRẬN

// Cho ma trận vuông A kích thước N x N. Nhiệm vụ của bạn là hãy tính ma trận X = AK với K là số nguyên cho trước. Đáp số có thể rất lớn, hãy in ra kết quả theo modulo 10^9+7.

// Input:
// Dòng đầu tiên là số lượng bộ test T (T ≤ 100).
// Mỗi test bắt gồm một số nguyên N và K (1 ≤ N ≤ 10, 1 ≤ K ≤ 109) là kích thước của ma trận và số mũ.

// Output: 
// Với mỗi test, in ra kết quả của ma trận X.


// Input:                      Output
// 2
// 2 5                         
// 1 1                         8 5
// 1 0                         5 3
// 3 1000000000
// 1 2 3                       597240088 35500972 473761863
// 4 5 6                       781257150 154135232 527013321
// 7 8 9                       965274212 272769492 580264779


#include<bits/stdc++.h>
using namespace std;

#define ll long long

const ll MOD = 1e9 + 7;
int n;

struct Matrix{
    ll a[15][15];

    friend Matrix operator * (Matrix x, Matrix y){
        Matrix res;
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < n; ++j){
                res.a[i][j] = 0;
                for(int k = 0; k < n; ++k){
                    res.a[i][j] += x.a[i][k] * y.a[k][j];
                    res.a[i][j] %= MOD;
                }
            }
        }
        return res;
    }
};

Matrix binpow(Matrix a, int k){
    if(k == 1) return a;
    Matrix x = binpow(a, k / 2);
    if(k % 2 == 0) return x * x;
    return x * x * a;
}

int main(){
    int t; cin >> t;
    while(t--){
        int k; cin >> n >> k;

        Matrix x;
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < n; ++j){
                cin >> x.a[i][j];
            }
        }

        Matrix res = binpow(x, k);

        for(int i = 0; i < n; ++i){
            for(int j = 0; j < n; ++j){
                cout << res.a[i][j] << " ";
            }
            cout << endl;
        }
    }
}