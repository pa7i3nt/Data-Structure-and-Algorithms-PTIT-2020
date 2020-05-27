#include <bits/stdc++.h>
using namespace std;

void result(int arr[], int n) {
    int i, start = 0, end = n - 1, max, min;

    for (start = 0; start < n - 1; start++) {
        if (arr[start] > arr[start + 1])
            break;
    }

    if (start == (n - 1)) {
        cout << -1 << endl;
        return;
    }

    for (end = n - 1; end > 0; end--) {
        if (arr[end] < arr[end - 1])
            break;
    }

    max = arr[start];
    min = arr[start];

    for (i = start + 1; i <= end; i++) {
        if (arr[i] > max)
            max = arr[i];
        
        if (arr[i] < min)
            min = arr[i];
    }

    for (i = 0; i < start; i++) {
        if (arr[i] > min) {
            start = i;
            break;
        }
    }

    for (i = n - 1; i >= end + 1; i--) {
        if (arr[i] < max) {
            end = i;
            break;
        }
    }

    cout << start + 1 << " " << end + 1 << endl;
}

int main() {
    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        
        result(arr, n);
    }
    return 0;
}