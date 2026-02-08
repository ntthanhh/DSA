//KIỂM TRA TÍNH LIÊN THÔNG MẠNH

// Cho đồ thị có hướng G=<V, E> được biểu diễn dưới dạng danh sách cạnh. Hãy kiểm tra xem đồ thị có liên thông mạnh hay không?

// Input:
// Dòng đầu tiên đưa vào T là số lượng bộ test.
// Những dòng tiếp theo đưa vào các bộ test. Mỗi bộ test gồm 2 dòng: dòng đầu tiên đưa vào hai số |V|, |E| tương ứng với số đỉnh và số cạnh; Dòng tiếp theo đưa vào các bộ đôi u, v tương ứng với một cạnh của đồ thị.
// T, |V|, |E| thỏa mãn ràng buộc: 1≤T≤100; 1≤|V|≤103; 1≤|E|≤|V|(|V|-1)/2;

// Output:
// Đưa ra “YES”, hoặc “NO” theo từng dòng tương ứng với test là liên thông mạnh hoặc không liên thông mạnh.


// Input:                                      Output
// 1
// 6 9                                         YES
// 1 2 2 4 3 1 3 2 3 5 4 3 5 4 5 6 6 3

// Thuật toán Kosaraju Các bước thực hiện
// Bước 1: DFS trên đồ thị gốc
//     Khởi tạo một ngăn xếp rỗng
//     Thực hiện DFS trên đồ thị ban đầu
//     Sau khi duyệt xong một đỉnh (đã duyệt hết các đỉnh kề của nó)
//     → đẩy đỉnh đó vào ngăn xếp
// Mục đích: lưu thứ tự kết thúc DFS của các đỉnh

// Bước 2: Đảo chiều đồ thị
//     Lật ngược hướng tất cả các cạnh của đồ thị ban đầu
//     Thu được đồ thị chuyển vị (transpose graph)

// Bước 3: DFS trên đồ thị đảo
//     Lấy từng đỉnh ra khỏi ngăn xếp (từ trên xuống)
//     Nếu đỉnh đó chưa được thăm trong đồ thị đảo:
//     Chọn đỉnh đó làm đỉnh bắt đầu
//     Thực hiện DFS trên đồ thị đảo
//     Các đỉnh duyệt được trong lần DFS này tạo thành một thành phần liên thông mạnh
//     Mỗi lần DFS ở Bước 3 thu được 1 thành phần liên thông mạnh
//     Lặp đến khi ngăn xếp rỗng

#include<bits/stdc++.h>
using namespace std;

void DFS1(int u, vector<int> adj[], int visited[], stack<int> &st){
    visited[u] = 1;
    for(int v : adj[u]){
        if(!visited[v]){
            DFS1(v, adj, visited, st);
        }
    }
    st.push(u);
}

void DFS2(int u, vector<int> re_adj[], int visited[]){
    visited[u] = 1;
    for(int v : re_adj[u]){
        if(!visited[v]){
            DFS2(v, re_adj, visited);
        }
    }
}

int main(){
    int t; cin >> t;
    while(t--){
        int n, m; cin >> n >> m;

        vector<int> adj[1005], re_adj[1005];
        int visited[1005];
        stack<int> st;

        memset(visited, 0, sizeof(visited));

        for(int i = 0; i < m; ++i){
            int x, y; cin >> x >> y;
            adj[x].push_back(y);
            re_adj[y].push_back(x);
        }

        for(int i = 1; i <= n; ++i){
            if(!visited[i]){
                DFS1(i, adj, visited, st);
            }
        }

        memset(visited, 0, sizeof(visited));
        int cnt = 0;

        while(!st.empty()){
            int u = st.top(); st.pop();
            if(!visited[u]){
                DFS2(u, re_adj, visited);
                ++cnt;
            }
        }

        cout << (cnt == 1 ? "YES\n" : "NO\n");
    }
}