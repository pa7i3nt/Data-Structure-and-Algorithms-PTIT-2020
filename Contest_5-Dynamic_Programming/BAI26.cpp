#include <bits/stdc++.h>
using namespace std;

int L[105][25005], n, v, a[105];
int tinh() {
    int i, j;
    memset(L, 0, sizeof(L));
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= v; j++) {
            if (j >= a[i] && L[i-1][j - a[i]] + a[i] > L[i-1][j])
                L[i][j] = L[i-1][j-a[i]] + a[i];
            else
                L[i][j] = L[i-1][j];
        }
    }
    return L[n][v];
}

int main() {
    int i;
    cin >> v >> n;
    for (i = 1; i <= n; i++)
        cin >> a[i];
    cout << tinh() << endl;
}