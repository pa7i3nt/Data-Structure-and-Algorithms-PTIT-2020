#include <bits/stdc++.h>
using namespace std;

int minSwaps(int a[], int n) {
    int c = 0, i, t;
    int temp[n];
    
    for (i = 0; i < n; i++)
        temp[i] = a[i];
    sort(temp, temp + n);
    
    for (i = 0; i < n; i++) {
        a[i] = lower_bound(temp, temp + n, a[i]) - temp;
    }
    
    for (i = 0; i < n - 1; i++) {
        while (i != a[i]) {
            t = a[a[i]];
            a[a[i]] = a[i];
            a[i] = t;
            c += 1;

        }
    }
    
    return c;
}

int main() {
    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++)
            cin >> arr[i];

        cout << minSwaps(arr, n) << endl;
    }
    return 0;
}