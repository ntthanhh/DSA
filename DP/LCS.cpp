// XÂU CON CHUNG DÀI NHẤT

// Cho 2 xâu S1 và S2. Hãy tìm xâu con chung dài nhất của 2 xâu này (các phần tử
// không nhất thiết phải liên tiếp nhau).

// Input: Dòng đầu tiên là số lượng bộ test T (T ≤ 20). Mỗi test gồm hai dòng,
// mô tả xâu S1 và S2, mỗi xâu có độ dài không quá 1000 và chỉ gồm các chữ cái
// in hoa.

// Output:  Với mỗi test, in ra độ dài dãy con chung dài nhất trên một dòng.

// Input:           Output
// 2
// AGGTAB           4
// GXTXAYB
// AA               0
// BB

#include <bits/stdc++.h>
using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
    string s1, s2;
    cin >> s1 >> s2;

    int x = s1.size(), y = s2.size();
    vector<vector<int>> dp(x + 1, vector<int>(y + 1));

    for (int i = 0; i <= x; ++i) {
      for (int j = 0; j <= y; ++j) {
        if (i == 0 || j == 0)
          dp[i][j] = 0;

        else {
          if (s1[i - 1] == s2[j - 1])
            dp[i][j] = dp[i - 1][j - 1] + 1;

          else
            dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
      }
    }

    cout << dp[x][y] << endl;
  }
}