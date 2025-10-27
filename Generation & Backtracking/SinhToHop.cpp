#include <bits/stdc++.h>
using namespace std;

// Bước 1: i ← k
// Bước 2: while (i > 0 and a[i] == n - k + i) do i ← i - 1
//     → tức là tìm phần tử đầu tiên từ phải sang trái chưa đạt “giới hạn tối đa”
// Bước 3: nếu i == 0 thì đã là tổ hợp cuối cùng (kết thúc)
// Bước 4: tăng a[i] lên 1
// Bước 5: với mọi j > i, gán a[j] = a[j-1] + 1


int main() {
    int n, k;
    cin >> n >> k;
    vector<int> a(k + 1);
    // Bắt đầu bằng tổ hợp đầu tiên: 1, 2, ..., k
    for (int i = 1; i <= k; i++) a[i] = i;

    bool stop = false;
    while (!stop) {
        // In tổ hợp hiện tại
        for (int i = 1; i <= k; i++) cout << a[i] << ' ';
        cout << '\n';

        // Tìm tổ hợp kế tiếp
        int i = k;
        while (i > 0 && a[i] == n - k + i) i--;
        if (i == 0) stop = true; // đã là tổ hợp cuối cùng
        else {
            a[i]++;
            for (int j = i + 1; j <= k; j++)
                a[j] = a[j - 1] + 1;
        }
    }
}
