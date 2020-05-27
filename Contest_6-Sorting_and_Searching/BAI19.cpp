#include <bits/stdc++.h>
using namespace std;

void result(int arr[], int n) {
    stable_sort(arr, arr + n);
    int tmp = 0, count = 0;
    for (int i = 0; i < n - 1; i++) {
        tmp = arr[i + 1] - arr[i];
        if (tmp > 1)
            count += (tmp - 1);
    }
    cout << count << endl;
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