#include <bits/stdc++.h>
using namespace std;

void result(int arr[], int n, int k) {
    stable_sort(arr, arr + n);
    for (int i = n - 1; i > n - k - 1; i--)
        cout << arr[i] << " ";
    cout << endl;
}

int main() {
    int t, n, k;
    cin >> t;
    while (t--) {
        cin >> n >> k;
        int arr[n];
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        
        result(arr, n, k);
    }
    return 0;
}