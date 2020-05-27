#include <bits/stdc++.h>
using namespace std;

void result(int arr[], int n) {
    int left, right, min_sum;
    int sum, min_left, min_right;

    min_left = 0;
    min_right = 1;
    min_sum = arr[0] + arr[1];

    for (left = 0; left < n; left++) {
        for (right = left + 1; right < n; right++) {
            sum = arr[left] + arr[right];
            if (abs(min_sum) > abs(sum)) {
                min_sum = sum;
                min_left = left;
                min_right = right;
            }
        }
    }

    cout << arr[min_left] + arr[min_right] << endl;
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