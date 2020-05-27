#include <bits/stdc++.h>
using namespace std;

int result(int arr[], int n, int k) {
    int res = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (arr[i] + arr[j] == k)
                res++;
        }
    }
    return res;
}

int main() {
    int t, n, k;
    cin >> t;
    while (t--) {
        cin >> n >> k;
        int arr[n];
        for (int i = 0; i < n; i++)
            cin >> arr[i];

        cout << result(arr, n, k) << endl;
    }
    return 0;
}