#include <bits/stdc++.h>
using namespace std;

int n, f[1005], arr[1005];

int result() {
    int res_tmp = 1;
    f[1] = 1;
    for (int i = 2; i <= n; i++) {
        f[i] = 1;
        for (int j = 1; j < i; j++) {
            if (arr[i] >= arr[j] && f[i] < f[j] + 1)
                f[i] = f[j] + 1;
        }

        res_tmp = max(res_tmp, f[i]);
    }

    return n - res_tmp;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 1; i <= n; i++)
            cin >> arr[i];

        cout << result() << endl;
    }
    return 0;
}