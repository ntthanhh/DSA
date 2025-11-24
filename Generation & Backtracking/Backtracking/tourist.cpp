#include<bits/stdc++.h>
using namespace std;

int n, c[105][105], X[105];
int visited[105];
int d = 0, ans = INT_MAX, cmin = INT_MAX;

// Cấu hình X1, X2, X3, ... , Xn
// X[i] : Số thứ tự thành phố thứ i mà người du lịch đi qua

void nhap(){
    cin >> n;
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= n; ++j){
            cin >> c[i][j];
            if(c[i][j] != 0){
                cmin = min(cmin, c[i][j]);
            }
        }
    }
    memset(visited, 0, sizeof(visited));
}

// Đi tìm X[i]
void Try(int i){
    for(int j = 1; j <= n; ++j){
        if(!visited[j]){
            visited[j] = 1;
            X[i] = j;
            d += c[X[i - 1]][X[i]];
            if(i == n){
                // Cập nhật kết quả
                ans = min(ans, d + c[X[n]][1]);
            }
            else if(d + (n - i + 1) * cmin < ans){
                Try(i + 1);
            }
            // backtrack
            visited[j] = 0;
            d -= c[X[i - 1]][X[i]];
        }
    }
}

int main(){
    nhap();
    X[1] = 1; visited[1] = 1;
    Try(2);
    cout << ans << endl;
}