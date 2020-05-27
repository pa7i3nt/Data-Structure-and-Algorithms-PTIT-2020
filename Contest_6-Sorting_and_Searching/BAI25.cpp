#include <bits/stdc++.h>
using namespace std;

void result(int arr[], int n) {
    sort(arr, arr + n);
    if (arr[0] == arr[n - 1]) {
        cout << -1 << endl;
        return;
    }

    int tmp;
    for (int i = 1; i < n; i++) {
        if (arr[0] < arr[i]) {
            tmp = arr[i];
            break;
        }
    }

    cout << arr[0] << " " << tmp << endl;
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