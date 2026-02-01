//DÃY CON TĂNG DÀI NHẤT

// Cho một dãy số nguyên gồm N phần tử A[1], A[2], ... A[N]. Biết rằng dãy con tăng là 1 dãy A[i1],... A[ik]thỏa mãn i1 < i2 < ... < ik và A[i1] < A[i2] < .. < A[ik].Hãy cho biết dãy con tăng dài nhất của dãy này có bao nhiêu phần tử? 

// Input: Dòng 1 gồm 1 số nguyên là số N (1 ≤ N ≤ 1000). Dòng thứ 2 ghi N số nguyên A[1], A[2], .. A[N] (1 ≤ A[i] ≤ 1000). 

// Output: Ghi ra độ dài của dãy con tăng dài nhất.

// Input               Output
// 1 2 5 4 6 2         6
// 4

//O(n^2)

#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; cin >> n;

    vector<int> a(n); 
    for(int i = 0; i < n; ++i) cin >> a[i];

    vector<int> dp(n, 1);
    //dp[i] : độ dài của dãy con tăng dài nhất kết thúc ở chỉ số i
    //dp[i] = max(dp[i], dp[j] + 1) Nếu a[i] > a[j]
     
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < i; ++j){
            if(a[i] > a[j]) dp[i] = max(dp[i], dp[j] + 1);
        }
    }
    
    cout << *max_element(dp.begin(), dp.end()) << endl;
    return 0;
}