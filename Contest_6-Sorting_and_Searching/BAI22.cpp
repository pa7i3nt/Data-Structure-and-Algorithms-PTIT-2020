#include <bits/stdc++.h>
using namespace std;

int binarySearch(int arr[], int left, int right, int x) {
    if (right >= left) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == x)
            return 1;
        
        if (arr[mid] > x)
            return binarySearch(arr, left, mid - 1, x);
        
        return binarySearch(arr, mid + 1, right, x);
    }

    return -1;   
}

int main() {
    int t, n, x;
    cin >> t;
    while (t--) {
        cin >> n >> x;
        int arr[n];
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        
        cout << binarySearch(arr, 0, n - 1, x) << endl;
    }
    return 0;
}