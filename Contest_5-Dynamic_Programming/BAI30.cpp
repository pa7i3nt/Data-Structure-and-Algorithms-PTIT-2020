#include <bits/stdc++.h>
using namespace std;

int f[10005], n;

int res() {
    f[0] = 0; f[1] = 1;
    f[2] = 2; f[3] = 3;

    for (int i = 4; i <= n; i++) {
        f[i] = i;
        for (int j = 1; j * j <= i; j++)
            f[i] = min(f[i], f[i - j * j] + 1);
    }

    return f[n];
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        cin >> n;
        cout << res() << endl;
    }
    return 0;
}