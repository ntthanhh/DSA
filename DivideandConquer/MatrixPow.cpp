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