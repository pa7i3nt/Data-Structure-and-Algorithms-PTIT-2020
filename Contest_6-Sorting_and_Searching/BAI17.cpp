#include <bits/stdc++.h>
using namespace std;

long long result(long long arr1[], long long arr2[], int n, int m) {
    stable_sort(arr1, arr1 + n, greater<int>());
    stable_sort(arr2, arr2 + m);

    return (arr1[0] * arr2[0]);
}

int main() {
    int t, n, m;
    cin >> t;
    while (t--) {
        cin >> n >> m;
        long long arr1[n], arr2[m];
        for (int i = 0; i < n; i++)
            cin >> arr1[i];

        for (int j = 0; j < m; j++)
            cin >> arr2[j];

        cout << result(arr1, arr2, n, m) << endl;
    }
    return 0;
}