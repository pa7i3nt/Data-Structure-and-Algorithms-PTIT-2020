#include <bits/stdc++.h>
using namespace std;

int binarySearch(int arr[], int left, int right, int k) {
    if (right >= left) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == k)
            return mid;

        if (arr[mid] > k)
            return binarySearch(arr, left, mid - 1, k);
        
        return binarySearch(arr, mid + 1, right, k);
    }

    return -1;
}

int findPivot(int arr[], int left, int right) {
    if (right < left)
        return -1;
    
    if (right == left)
        return left;

    int mid = left + (right - left) / 2;

    if (mid < right && arr[mid] > arr[mid + 1])
        return mid;

    if (mid > left && arr[mid] < arr[mid - 1])
        return (mid - 1);

    if (arr[left] >= arr[mid])
        return findPivot(arr, left, mid - 1);
    
    return findPivot(arr, mid + 1, right);
}

int result(int arr[], int n, int k) {
    int pivot = findPivot(arr, 0, n - 1);

    if (pivot == -1)
        return binarySearch(arr, 0, n - 1, k);
    
    if (arr[pivot] == k)
        return pivot;

    if (arr[0] <= k)
        return binarySearch(arr, 0, pivot - 1, k);
    
    return binarySearch(arr, pivot + 1, n - 1, k);
}

int main() {
    int t, n, k;
    cin >> t;
    while (t--) {
        cin >> n >> k;
        int arr[n];
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        
        cout << result(arr, n, k) + 1 << endl;
    }
    return 0;
}