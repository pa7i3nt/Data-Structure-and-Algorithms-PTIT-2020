#include <bits/stdc++.h>
using namespace std;
#define MODULO 1000000007

long long n, arr[10000000];

int maxRes() {
    long long res = 0;
    sort(arr, arr + n);
    for (int i = n-1; i > 0; i--)
        res += arr[i] * i;
    return res % MODULO;
}

int main() {
    int test;
    cin >> test;
    while (test--) {
        cin >> n;
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        cout << maxRes() << "\n";
    }
    return 0;
}