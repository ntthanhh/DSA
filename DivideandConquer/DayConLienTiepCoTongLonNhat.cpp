//DÃY CON LIÊN TIẾP CÓ TỔNG LỚN NHẤT

// Cho mảng A[] gồm N số có cả các số âm và số dương. Nhiệm vụ của bạn là tìm mảng con liên tục có tổng lớn nhất của mảng. Ví dụ với mảng A[]={-2, -5, 6, -2,-3, 1, 5, -6} ta có kết quả là 7 tương ứng với dãy con {6, -2, -3, 1, 5}.

// Input:
// Dòng đầu tiên đưa vào số lượng bộ test T.
// Những dòng kế tiếp đưa vào các bộ test. Mỗi bộ test gồm 2 dòng: dòng thứ nhất đưa vào hai số N tương ứng với số phần tử của mảng; dòng tiếp theo đưa vào N số A[i]; các số được viết cách nhau một vài khoảng trống.
// T, N, A[i] thỏa mãn ràng buộc: 1≤T≤100;  1≤ N≤100; -100≤A[i] ≤100.

// Output:
// Đưa ra tổng con liên tục lớn nhất của mỗi test theo từng dòng.

// Input                           Output
// 1
// 8                               7
// -2 -5 6 -2 -3 1 5 -6

#include<bits/stdc++.h>
using namespace std;

int Crossing(int a[], int l, int m, int r){
    int sum = 0;
    int maxLeft = INT_MIN;
    int maxRight = INT_MIN;

    for(int i = m; i >= l; --i){
        sum += a[i];
        maxLeft = max(maxLeft, sum);
    }

    sum = 0;
    for(int i = m + 1; i <= r; ++i){
        sum += a[i];
        maxRight = max(maxRight, sum);
    }

    return maxLeft + maxRight;
}


int XuLy(int a[], int l, int r){
    int m = (l + r) / 2;
    if(l == r) return a[l];

    return max({
        XuLy(a, l, m),
        XuLy(a, m + 1, r),
        Crossing(a, l, m, r)
    });
}

int main(){
    int t; cin >> t;
    while(t--){
        int n; cin >> n;

        int a[n];
        for(auto &x : a) cin >> x;

        cout << XuLy(a, 0, n - 1) << endl;
    }
}