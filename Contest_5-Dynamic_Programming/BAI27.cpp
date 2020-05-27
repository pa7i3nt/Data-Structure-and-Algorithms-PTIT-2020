#include <bits/stdc++.h>
using namespace std;

int L[1005][1005], n, v, a[1005], c[1005];
int tinh() {
    int i, j;
    memset(L, 0, sizeof(L));
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= v; j++) {
            if (j >= a[i] && L[i-1][j - a[i]] + c[i] > L[i-1][j])
                L[i][j] = L[i-1][j-a[i]] + c[i];
            else
                L[i][j] = L[i-1][j];
        }
    }
    return L[n][v];
}

int main() {
    int t, i;
    cin >> t;
    while (t--) {
        cin >> n >> v;
        for (i = 1; i <= n; i++)
            cin >> a[i];
        for (i = 1; i <= n; i++)
            cin >> c[i];
        cout << tinh() << endl;
    }
}