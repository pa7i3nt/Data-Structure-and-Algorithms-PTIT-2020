#include <bits/stdc++.h>
using namespace std;

const int M = 1e9 + 7;

long long mat[105][905];

long long updateMat(int n, int k) {
    if (n == 0)
        return k == 0;

    if (mat[n][k] != INT_MIN)
        return mat[n][k];
    
    long long res = 0;

    for (int i = 0; i <= 9; i++) {
        if (k - i >= 0) {
            res += updateMat(n - 1, k - i);
            res %= M;
        }
    }

    mat[n][k] = res;
    return res;
}

long long result(int n, int k) {
    if (k > n * 9)
        return 0;

    long long res = 0;

    for (int i = 1; i <= 9; i++) {
        if (k - i >= 0) {
            res += updateMat(n - 1, k - i);
            res %= M;
        }
    }

    return res;
}

int main() {
    for (int i = 0; i <= 100; i++)
        for (int j = 0; j <= 900; j++)
            mat[i][j] = INT_MIN;

    int t, n, k;
    cin >> t;
    while (t--) {
        cin >> n >> k;
        cout << result(n, k) << endl;
    }
    return 0;
}