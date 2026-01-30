#include <bits/stdc++.h>
using namespace std;

void Merge(int a[], int l, int m, int r){
    vector<int> left(a + l, a + m + 1);
    vector<int> right(a + m + 1, a + r + 1);

    int i = 0, j = 0;

    while(i < left.size() && j < right.size()){
        if(left[i] <= right[j]){
            a[l++] = left[i++];
        } else {
            a[l++] = right[j++];
        }
    }

    while(i < left.size()){
        a[l++] = left[i++];
    }

    while(j < right.size()){
        a[l++] = right[j++];
    }
}

void MergeSort(int a[], int l, int r){
    if(l >= r) return;

    int m = (l + r) / 2;
    MergeSort(a, l, m);
    MergeSort(a, m + 1, r);
    Merge(a, l, m, r);
}

int main(){
    int n; 
    cin >> n;
    int a[n];
    for(int i = 0; i < n; ++i) cin >> a[i];

    MergeSort(a, 0, n - 1);

    for(int x : a) cout << x << " ";
}
