#include <bits/stdc++.h>
using namespace std;

void result(int arr1[], int arr2[], int m, int n) {
    int res[n + m - 1] = {0};
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; j++) {
            res[i + j] += arr1[i] * arr2[j];
        }
    }

    for (int i = 0; i < m + n - 1; i++)
        cout << res[i] << " ";
    cout << endl;
}

int main() {
    int t, m, n;
    cin >> t;
    while (t--) {
        cin >> m >> n;
        int arr1[m], arr2[n];

        for (int i = 0; i < m; i++)
            cin >> arr1[i];

        for (int j = 0; j < n; j++)
            cin >> arr2[j];

        result(arr1, arr2, m, n);
    }
    return 0;
}