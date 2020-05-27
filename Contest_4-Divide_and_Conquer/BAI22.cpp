#include <bits/stdc++.h>
using namespace std;

int binarySearch(int arr[], int left, int right, int k) {
    if (left > right)
        return 0;
    else {
        int mid = (left + right) / 2;
        if (arr[mid] == k)
            return mid;

        if (arr[mid] > k)
            return binarySearch(arr, left, mid - 1, k);

        return binarySearch(arr, mid + 1, right, k);
    }
}

int main() {
    int test, n, k;
    cin >> test;
    while (test--) {
        cin >> n >> k;
        int arr[n];
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        if (binarySearch(arr, 0, n - 1, k) == 0)
            cout << "NO\n";
        else 
            cout << binarySearch(arr, 0, n - 1, k) + 1 << "\n";
    }
    return 0;
}