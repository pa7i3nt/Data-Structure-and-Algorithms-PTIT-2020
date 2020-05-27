#include <bits/stdc++.h>
using namespace std;

long long maxSum(long long arr1[], long long arr2[], int n) {
    sort(arr1, arr1 + n, greater<int>());
    sort(arr2, arr2 + n);
    long long sum = 0;
    for (int i = 0; i < n; i++) {
        sum += arr1[i] * arr2[i];
    }
    return sum;
}

int main() {
    int test, n;
    cin >> test;
    while (test--) {
        cin >> n;
        long long arr1[n], arr2[n];

        for (int i = 0; i < n; i++)
            cin >> arr1[i];

        for (int i = 0; i < n; i++)
            cin >> arr2[i];

        cout << maxSum(arr1, arr2, n) << "\n";
    }
    return 0;
}