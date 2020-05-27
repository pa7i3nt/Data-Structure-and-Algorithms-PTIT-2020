#include <bits/stdc++.h>
using namespace std;

int maxAtMid(int arr[], int left, int mid, int right) {
    int sum = 0, max_left = INT_MIN, max_right = INT_MIN;

    for (int i = mid; i >= left; i--) {
        sum += arr[i];
        if (sum > max_left)
            max_left = sum;
    }

    sum = 0;
    for (int i = mid + 1; i <= right; i++) {
        sum += arr[i];
        if (sum > max_right)
            max_right = sum;
    }

    return max(max(max_left, max_right), max_left + max_right);
}

int findRes(int arr[], int left, int right) {
    if (left == right)
        return arr[left];
    
    int mid = (left + right) / 2;

    return max(max(findRes(arr, left, mid), findRes(arr, mid + 1, right)),
                        maxAtMid(arr, left, mid, right));
}

int main() {
    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        
        cout << findRes(arr, 0, n - 1) << endl;
    }
    return 0;
}