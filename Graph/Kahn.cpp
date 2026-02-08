//KIỂM TRA CHU TRÌNH TRÊN ĐỒ THỊ CÓ HƯỚNG

// Cho đồ thị có hướng G=<V, E> được biểu diễn dưới dạng danh sách cạnh. Hãy kiểm tra xem đồ thị có tồn tại chu trình hay không?

// Input:
// Dòng đầu tiên đưa vào T là số lượng bộ test.
// Những dòng tiếp theo đưa vào các bộ test. Mỗi bộ test gồm 2 dòng: dòng đầu tiên đưa vào hai số |V|, |E| tương ứng với số đỉnh,  số cạnh của đồ thị; Dòng tiếp theo đưa vào các bộ đôi u, v tương ứng với một cạnh của đồ thị.
// T, |V|, |E| thỏa mãn ràng buộc: 1≤T≤100; 1≤|V|≤103; 1≤|E|≤|V|(|V|-1)/2;

// Output:
// Đưa ra YES hoặc “NO” kết quả test theo từng dòng tương ứng với đồ thị tồn tại hoặc không tồn tại chu trình.


// Input:                                  Output:
// 1   
// 6 9                                     YES 
// 1 2 2 4 3 1 3 2 3 5 4 3 5 4 5 6 6 4

// Các bước thuật toán Kahn
// Bước 1
//     Tính in-degree(bán bậc vào) cho mỗi đỉnh

// Bước 2
//     Cho tất cả đỉnh có in-degree = 0 vào queue

// Bước 3
//     Trong khi queue chưa rỗng:
//     Lấy 1 đỉnh u ra
//     Đưa u vào kết quả topo
//     Với mỗi cạnh u → v:
//     giảm in-degree[v]
//     nếu in-degree[v] == 0 → đẩy vào queue


#include<bits/stdc++.h>
using namespace std;

bool Kahn(vector<int> adj[], int d[1005], int n){
    queue<int> q;
    for(int i = 1; i <= n; ++i){
        if(d[i] == 0) q.push(i);
    }

    vector<int> ve;
    while(!q.empty()){
        int u = q.front(); q.pop();
        ve.push_back(u);

        for(auto v : adj[u]){
            --d[v];
            if(d[v] == 0) q.push(v);
        }
    }

    if(ve.size() != n) return true;
    return false;
}

int main(){
    int t; cin >> t;
    while(t--){
        int n, m; cin >> n >> m;

        vector<int> adj[1005];
        int d[1005];

        memset(d, 0, sizeof(d));

        for(int i = 0; i < m; ++i){
            int x, y; cin >> x >> y;
            adj[x].push_back(y);
            d[y]++;
        }

        if(Kahn(adj, d, n)) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}