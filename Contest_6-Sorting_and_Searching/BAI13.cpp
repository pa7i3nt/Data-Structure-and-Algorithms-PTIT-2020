#include <bits/stdc++.h>
using namespace std;

int result(int arr[], int n, int k) {
    int *low = lower_bound(arr, arr + n, k);

    if (low == (arr + n) || *low != k)
        return -1;

    int *high = upper_bound(low, arr + n, k);

    return high - low;
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