#include<bits/stdc++.h>

using namespace std;
int X[10000], A[10000];
int main() {
    int t, n, k;
    cin >> t;
    while (t--) {
        cin >> n >> k;
        for (int i = 1; i <= k; i++) {
            cin >> X[i];
        }
        int i = k;
        while (X[i] - X[i - 1] == 1) {
            i--;
        }
        int m = i;
        for (int a = 1; a < m; a++) A[a] = X[a];
        A[m] = X[m] - 1;
        for (int b = k; b >= m + 1; b--) {
            A[b] = n;
            n--;
        }
        for (int i = 1; i <= k; i++) {
            cout << A[i] << " ";
        }
        cout << endl;
    }
}