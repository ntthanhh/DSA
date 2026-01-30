#include<bits/stdc++.h>
using namespace std;

#define ll long long

ll F[100];
void Fibo(){
    F[0] = 0; F[1] = 1;
    for(int i = 2; i <= 92; ++i){
        F[i] = F[i - 1] + F[i - 2];
    }
}

char Find(int n, ll k){
    if(n == 1) return 'A';
    if(n == 2) return 'B';
    if(k <= F[n - 2]) return Find(n - 2, k);
    else return Find(n - 1, k - F[n - 2]);
}

int main(){
    Fibo();
    int t; cin >> t;
    while(t--){
        int n; ll k;
        cin >> n >> k;

        cout << Find(n, k) << endl;
    }
}