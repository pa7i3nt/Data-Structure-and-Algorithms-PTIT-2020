#include <bits/stdc++.h>
using namespace std;

long long x, y, f[105][105];

long long result() {
    for (long long i = 1; i <= x; i++)
        f[i][0] = 1;

    for (long long i = 1; i <= y; i++)
        f[0][i] = 1;

    for (long long i = 1; i <= y; i++)
        for (long long j = 1; j <= x; j++)
            f[j][i] = f[j - 1][i] + f[j][i-1];

    return f[x][y];
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        cin >> x >> y;
        cout << result() << endl;
    }
    return 0;
}