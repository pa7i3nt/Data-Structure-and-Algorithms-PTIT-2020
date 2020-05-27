#include <bits/stdc++.h>
using namespace std;

const int M = 1e9 + 7;

int n, k;
int res[100005];

long long solve() {
    res[0] = 1;
    for (int i = 1; i <= n; i++) {
        res[i] = 0;
        for (int j = i - 1; j >= 0 && j >= i - k; j--) {
            res[i] += res[j];
            res[i] %= M;
        }
        // cout << res[i] << endl;
    }
    return res[n];
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        cin >> n >> k;
        cout << solve() << endl;
    }
    return 0;
}