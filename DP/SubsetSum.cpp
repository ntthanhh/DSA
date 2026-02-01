//DÃY CON CÓ TỔNG BẰNG S

// Cho N  số nguyên dương tạo thành dãy A={A1, A2, ..., AN}. Tìm ra một dãy con của dãy A (không nhất thiết là các phần tử liên tiếp trong dãy) có tổng bằng S cho trước.

// Input: Dòng đầu ghi số bộ test T (T<10).  Mỗi bộ test có hai dòng, dòng đầu tiên ghi hai số nguyên dương N và S (0 < N ≤ 200) và S (0 < S ≤ 40000). Dòng tiếp theo lần lượt ghi N số hạng của dãy A là các số A1, A2, ..., AN (0 < Ai ≤ 200).

// Output:  Với mỗi bộ test, nếu bài toán vô nghiệm thì in ra “NO”, ngược lại in ra “YES”

// Input                       Output
// 2                       
// 5 6                        YES
// 1 2 4 3 5
// 10 15                      NO
// 2 2 2 2 2 2 2 2 2 2


#include<bits/stdc++.h>
using namespace std;

int main(){
    int t; cin >> t;
    while(t--){
        int n, S; cin >> n >> S;
        
        vector<int> a(n);
        for(auto &x : a) cin >> x;

        vector<int> dp(S + 1, 0);
        dp[0] = 1;

        for(int i = 0; i < n; ++i){
            for(int j = S; j >= a[i]; --j){
                if(dp[j - a[i]]) dp[j] = 1;
            }
        }

        if(dp[S]) cout << "YES" << endl;
        
        else cout << "NO" << endl;
    }
}