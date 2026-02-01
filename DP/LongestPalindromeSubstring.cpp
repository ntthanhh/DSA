//XÂU CON ĐỐI XỨNG DÀI NHẤT

// Cho xâu S chỉ bao gồm các ký tự viết thường và dài không quá 1000 ký tự. Hãy tìm xâu con đối xứng dài nhất của S.

// Input:
// Dòng đầu tiên là số lượng bộ test T (T ≤ 10).
// Mỗi test gồm một xâu S có độ dài không vượt quá 1000, chỉ gồm các kí tự thường.

// Output:  Với mỗi test, in ra đáp án tìm được.

// Input           Output
// 2               
// abcbadd         5
// aaaaa           5

#include<bits/stdc++.h>
using namespace std;

int main(){
    int t; cin >> t;
    while(t--){
        string s; cin >> s;

        int n = s.size();
        s = 'x' + s;
        int dp[n + 1][n + 1];
        for(int i = 1; i <= n; ++i) dp[i][i] = 1;

        int res = 1;
        for(int len = 2; len <= n; ++len){
            for(int i = 1; i <= n - len + 1; ++i){
                int j = i + len - 1;

                if(s[i] == s[j] && len == 2) dp[i][j] = 1;

                else dp[i][j] = dp[i + 1][j - 1] && (s[i] == s[j]);

                if(dp[i][j]) res = max(res, len);
            }
        }
        
        cout << res << endl;
    }
}