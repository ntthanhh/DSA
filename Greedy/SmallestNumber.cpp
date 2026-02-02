//SỐ NHỎ NHẤT

// Cho hai số nguyên dương S và D, trong đó S là tổng các chữ số và D là số các chữ số của một số. Nhiệm vụ của bạn là tìm số nhỏ nhất thỏa mãn S và D? Ví dụ với S = 9, D = 2 ta có số nhỏ nhất thỏa mãn S và D là 18.

// Input:
// Dòng đầu tiên đưa vào số lượng bộ test T.
// Những dòng kế tiếp đưa vào các bộ test. Mỗi bộ test là bộ 2 số S và D được viết trên một dòng.
// T, S, D thỏa mãn ràng buộc: 1≤T≤100;  1≤ S,D≤1000.

// Output:
// Đưa ra kết quả mỗi test theo từng dòng. Nếu không có đáp án, in ra -1.

// Input           Output
// 2       
// 9 2             18
// 20 3            299

#include<bits/stdc++.h>
using namespace std;

int main(){
    int t; cin >> t;
    while(t--){
        int n, k; cin >> n >> k;

        if(9 * k < n){
            cout << -1 << endl;
        }
        else {
            int a[k] = {0};
            n -= 1;

            for(int i = k - 1; i >= 1; --i){
                if(n >= 9){
                    a[i] = 9;
                    n -= 9;
                }
                else{
                    a[i] = n;
                    n = 0;
                }
            }

            a[0] += (n + 1);

            for(int i = 0; i < k; ++i){
                cout << a[i];
            }

            cout << endl;
        }
    }
}