//DIJKSTRA

// Cho đồ thị có trọng số không âm G=<V, E> được biểu diễn dưới dạng danh sách cạnh trọng số. Hãy viết chương trình tìm đường đi ngắn nhất từ đỉnh uÎV đến tất cả các đỉnh còn lại trên đồ thị.

// Input:
// Dòng đầu tiên đưa vào T là số lượng bộ test.
// Những dòng tiếp theo đưa vào các bộ test. Mỗi bộ test gồm |E|+1 dòng: dòng đầu tiên đưa vào hai ba số |V|, |E| tương ứng với số đỉnh và uÎV là đỉnh bắt đầu; |E| dòng tiếp theo mỗi dòng đưa vào bộ ba uÎV, vÎV, w tương ứng với một cạnh cùng với trọng số canh của đồ thị.
// T, |V|, |E| thỏa mãn ràng buộc: 1≤T≤100; 1≤|V|≤103; 1≤|E|≤|V|(|V|-1)/2;

// Output:
// Đưa ra kết quả của mỗi test theo từng dòng. Kết quả mỗi test là trọng số đường đi ngắn nhất từ đỉnh u đến các đỉnh còn lại của đồ thị theo thứ tự tăng dần các đỉnh.

// Input:          Output:
// 1
// 9  12 1         0 4 12 19 26 16 18 8 14
// 1  2   4
// 1  8   8
// 2  3   8
// 2  8   11
// 3  4   7
// 3  6   4
// 3  9   2
// 4  5   9
// 4  6  14
// 5  6  10
// 6  7  2
// 6  9  6

//DIJKSTRA

// Cho đồ thị có trọng số không âm G=<V, E> được biểu diễn dưới dạng danh sách cạnh trọng số. Hãy viết chương trình tìm đường đi ngắn nhất từ đỉnh uÎV đến tất cả các đỉnh còn lại trên đồ thị.

// Input:
// Dòng đầu tiên đưa vào T là số lượng bộ test.
// Những dòng tiếp theo đưa vào các bộ test. Mỗi bộ test gồm |E|+1 dòng: dòng đầu tiên đưa vào hai ba số |V|, |E| tương ứng với số đỉnh và uÎV là đỉnh bắt đầu; |E| dòng tiếp theo mỗi dòng đưa vào bộ ba uÎV, vÎV, w tương ứng với một cạnh cùng với trọng số canh của đồ thị.
// T, |V|, |E| thỏa mãn ràng buộc: 1≤T≤100; 1≤|V|≤103; 1≤|E|≤|V|(|V|-1)/2;

// Output:
// Đưa ra kết quả của mỗi test theo từng dòng. Kết quả mỗi test là trọng số đường đi ngắn nhất từ đỉnh u đến các đỉnh còn lại của đồ thị theo thứ tự tăng dần các đỉnh.

// Input:          Output:
// 1
// 9  12 1         0 4 12 19 26 16 18 8 14
// 1  2   4
// 1  8   8
// 2  3   8
// 2  8   11
// 3  4   7
// 3  6   4
// 3  9   2
// 4  5   9
// 4  6  14
// 5  6  10
// 6  7  2
// 6  9  6


#include<bits/stdc++.h>
using namespace std;

struct Edge{
    int x, y, w;
};


void BellmanFord(int s, vector<Edge> adj, int n){
	vector<int> d(n + 1, 1e9);
	d[s] = 0;

	for(int i = 0; i <= n - 1; ++i){
		for(auto a : adj){
			int u = a.x, v = a.y, w = a.w;
			if(d[u] < 1e9){
				if(d[v] > d[u] + w){
					d[v] = d[u] + w;
				}
			} 
		}
	}

	for(int i = 1; i <= n; ++i) cout << d[i] << " ";
}

int main(){
	int t; cin >> t;
	while(t--){
		int n, m, s; cin >> n >> m >> s;

		vector<Edge> adj;
		for(int i = 0; i < m; ++i){
			int x, y, w; cin >> x >> y >> w;

			adj.push_back({x, y, w});
			adj.push_back({y, x, w});
		}

		BellmanFord(s, adj, n);
		cout << endl;
	}
}