#include<bits/stdc++.h>
using namespace std;

const int MAXN = 100;
int a[MAXN], c[MAXN], F[MAXN][MAXN];
int XOPT[MAXN], X[MAXN];
int n, b, ind;
float w, FOPT = -32000, cost, weight = 0;

void nhap(){
    // n : Số lượng đồ vật; b : Trọng lượng túi
    cin >> n >> b;
    // a : mảng trọng lượng
    for(int i = 1; i <= n; ++i) cin >> a[i];
    // c : mảng giá trị sử dụng
    for(int i = 1; i <= n; ++i) cin >> c[i];
}

void Update(){
    if(cost > FOPT){
        FOPT = cost;
        for(int i = 1; i <= n; ++i) XOPT[i] = X[i];
    }
}

void Result(){
    for(int i = 1; i <= n; ++i) cout << XOPT[i] << " ";
}

void Branch_And_Bound(int i){
    int t = (b - weight) / a[i];
    for(int j = t; j >= 0; --j){
        X[i] = j;
        weight = weight + a[i] * X[i];
        cost = cost + c[i] * X[i];
        if(i == n) Update();
        else if(cost + c[i + 1] * (b - weight) / a[i + 1] > FOPT){
            Branch_And_Bound(i + 1);
        }
        weight = weight - a[i] * X[i];
        cost = cost - c[i] * X[i];
    }
}

int main(){
    nhap();
    Branch_And_Bound(1);
    Result();
}