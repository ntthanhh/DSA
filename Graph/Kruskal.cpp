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


// Thuật toán Kruskal
// Tư tưởng của thuật toán Kruskal là:
// 	Ở mỗi bước, ta sẽ chọn một cạnh có trọng số nhỏ nhất (chưa thuộc cây khung) và đưa vào cây khung nếu cạnh đó không tạo chu trình.
// 	Để cài đặt được thuật toán Kruskal, ta cần sử dụng cấu trúc dữ liệu DSU (Disjoint Set Union) để:
// 	Kiểm tra hai đỉnh có thuộc cùng một thành phần liên thông hay không
// 	Tránh việc tạo chu trình khi thêm cạnh
// Thuật toán sẽ kết thúc khi:
// 	Đã chọn đủ N - 1 cạnh, hoặc
// 	Không còn cạnh nào có thể thêm vào cây khung

#include<bits/stdc++.h>
using namespace std;

struct Canh{
	int x, y, w;
};

int parent[1005], sz[1005];

void Init(int n){
	for(int i = 1; i <= n; ++i){
		parent[i] = i;
		sz[i] = 1;
	}
}

int Find(int u){
	if(u == parent[u]) return u;
	return parent[u] = Find(parent[u]);
}

bool Union(int x, int y){
	x = Find(x);
	y = Find(y);
	if(x == y) return false;
	if(sz[x] < sz[y]){
		parent[x] = y;
		sz[y] += sz[x];
	}
	else {
		parent[x] = y;
		sz[y] += sz[x];
	}
	return true;
}

bool cmp(Canh a, Canh b){
	return a.w < b.w;
}

void Kruskal(vector<Canh> dscanh, int n, int m){
	vector<Canh> MST;
	int d = 0;
	sort(dscanh.begin(), dscanh.end(), cmp);

	for(int i = 0; i < m; ++i){
		if(MST.size() == n - 1) break;

		int x = dscanh[i].x, y = dscanh[i].y, w = dscanh[i].w;
		if(Union(x, y)){
			MST.push_back({x, y, w});
			d += w;
		}
	}
	cout << d << endl;
}

int main(){
	// freopen("TASK.inp", "r", stdin);
    // freopen("TASK.outt", "w", stdout);
	int t; cin >> t;
	while(t--){
		int n, m; cin >> n >> m;
		vector<Canh> dscanh;
		Init(n);

		bool ok = false;
		for(int i = 0; i < m; ++i){
			int a, b, c; cin >> a >> b >> c;

			dscanh.push_back({a, b, c});
		}

		Kruskal(dscanh, n, m);
	}
}