#include<bits/stdc++.h>
using namespace std;

int Lomuto_Partition(int a[], int l, int r){
    int x = a[r];
    int j = l - 1;
    for(int i = l; i < r; ++i){
        if(a[i] <= x){
            ++j;
            swap(a[j], a[i]);
        }
    }
    ++j;
    swap(a[j], a[r]);
    return j;
}

int Hoare_Partition(int a[], int l, int r){
    
}

void QuickSort(int a[], int l, int r){
    if(l < r){
        int p = Lomuto_Partition(a, l, r);
        QuickSort(a, l, p - 1);
        QuickSort(a, p + 1, r);
    }
}

int main(){
    int n; cin >> n;

    int a[n];
    for(int i = 0; i < n; ++i) cin >> a[i];

    QuickSort(a, 0, n - 1);
    for(int i = 0; i < n; ++i) cout << a[i] << " ";
}