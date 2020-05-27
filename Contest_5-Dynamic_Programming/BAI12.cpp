#include <bits/stdc++.h>
using namespace std;

int C[1005][1005], n, k;
int M = 1e9 + 7;

long long tinh(int n, int k) {
    long long res = 1;
    for (int i = n; i >= n - k + 1; i--) {
        res = res * i % M;
    }
    return res;
}

int main() {
    int test;
    cin >> test;
    while (test--) {
        cin >> n >> k;
        cout << tinh(n, k) << endl;
    }
    return 0;
}