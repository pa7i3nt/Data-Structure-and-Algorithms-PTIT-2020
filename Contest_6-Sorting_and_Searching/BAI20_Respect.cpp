#include <bits/stdc++.h>
using namespace std;

int binarySearch(int arr[], int left, int right, int x) {
    if (right >= left) {
        int mid = left + (right - left) / 2;

        if (arr[mid] <= x && arr[mid + 1] > x)
            return mid;

        if (arr[mid] > x)
            return binarySearch(arr, left, mid - 1, x);

        return binarySearch(arr, mid + 1, right, x);
    }
}

int main() {
    int t, n, x;
    cin >> t;
    while (t--) {
        cin >> n >> x;
        int arr[n + 1];
        for (int i = 0; i < n; i++)
            cin >> arr[i];

        long long res = 0;
        sort(arr, arr + n);

        for (int i = 0; i < n - 1; i++)
            res = res + binarySearch(arr, i + 1, n - 1, x + arr[i] - 1) - i;
        
        cout << res << endl;
    }
    return 0;
}