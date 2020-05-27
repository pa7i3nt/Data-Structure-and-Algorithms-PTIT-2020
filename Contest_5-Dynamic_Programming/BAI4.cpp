#include <bits/stdc++.h>
using namespace std;

int n, k;
// vector<int> f(1005, 55), g(55);

void result() {
    cin >> n >> k;
    vector<int> a(n);
    for (int &x : a) {
        cin >> x;
        x %= k;
    }
    vector<int> f(k, INT_MIN), g(k);
    f[0] = 0;
    for (int x: a) {
        for (int i = 0; i < k; i++) {
            g[i] = max(f[i], f[(i - x + k) % k] + 1);
        }
        f.swap(g);
    }

    cout << f[0] << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        result();
    }
    return 0;
}