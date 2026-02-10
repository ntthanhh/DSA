//KRUSKAL

// Cho đồ thị vô hướng có trọng số G=<V, E, W>. Nhiệm vụ của bạn là hãy xây dựng một cây khung nhỏ nhất của đồ thị bằng thuật toán Kruskal.

// Input:
// Dòng đầu tiên đưa vào số lượng bộ test T.
// Những dòng kế tiếp đưa vào các bộ test. Mỗi bộ test gồm hai phần: phần thứ nhất đưa vào hai số V, E tương ứng với số đỉnh và số cạnh của đồ thị; phần thứ 2 đưa vào E cạnh của đồ thị, mỗi cạnh là một bộ 3: đỉnh đầu, đỉnh cuối và trọng số của cạnh.
// T, S, D thỏa mãn ràng buộc: 1≤T≤100;  1≤V≤100; 1≤E, W≤10000.

// Output:
// Đưa ra kết quả mỗi test theo từng dòng.


// Input			Ouput
// 2
// 3 3				4
// 1 2 5
// 2 3 3
// 1 3 1
// 2 1				5
// 1 2 5


// Thuật toán Prim
// Tư tưởng của thuật toán Prim là duy trì 2 tập đỉnh:
// 	V: tập các đỉnh chưa thuộc cây khung
// 	MST: tập các đỉnh đã thuộc cây khung

// Thuật toán Prim sẽ bắt đầu với một đỉnh bất kỳ của đồ thị.
// 	Ban đầu:
// 		MST = {s}   (s là đỉnh bắt đầu)
// 		V = V \ {s}

// 		Ở mỗi bước, thuật toán chọn một cạnh có trọng số nhỏ nhất sao cho:
// 		Một đỉnh của cạnh thuộc MST
// 		Đỉnh còn lại thuộc V

// 	Sau đó:
// 		Đưa đỉnh mới vào MST
// 		Cập nhật lại hai tập V và MST
// 		Thuật toán kết thúc khi:
// 		Cây khung có đủ n − 1 cạnh, hoặc
// 		Tập V rỗng

#include<bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;
#define ll long long

void Prim(int u, vector<ii> adj[], int used[]){
	used[u] = 1;

	priority_queue<ii, vector<ii>, greater<ii>> q;
	for(auto x : adj[u]){
		if(!used[x.first]){
			q.push({x.second, x.first});
		}
	}

	int d = 0;
	while(!q.empty()){
		auto x = q.top(); q.pop();
		if(used[x.second]) continue;

		used[x.second] = 1;
		d += x.first;

		for(auto y : adj[x.second]){
			if(!used[y.first]){
				q.push({y.second, y.first});
			}
		}
	}

	cout << d << endl;
}

int main(){
	int t; cin >> t;
	while(t--){
		int n, m; cin >> n >> m;

		vector<ii> adj[10005];
		int used[10005];
		memset(used, 0, sizeof(used));

		for(int i = 0; i < m; ++i){
			int x, y, w; cin >> x >> y >> w;
			adj[x].push_back({y, w});
			adj[y].push_back({x, w});
		}

		Prim(1, adj, used);
	}
}