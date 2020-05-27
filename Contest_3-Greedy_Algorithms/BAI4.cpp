#include <bits/stdc++.h>
using namespace std;

long long min_sum(int n, long long arr[]) {
    sort(arr, arr + n);
    long long a = 0, b = 0;
    for (int i = 0; i < n; i++) {
        // bitwise (so sanh voi bit 1 o cuoi cung)
        if (i & 1)
            a = a * 10 + arr[i];
        else 
            b = b * 10 + arr[i];
    }
    return a + b;
}

int main() {
    int test, n;
    cin >> test;
    while (test--) {
        cin >> n;
        long long arr[n];
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        cout << min_sum(n, arr) << endl;
    }
    return 0;
}