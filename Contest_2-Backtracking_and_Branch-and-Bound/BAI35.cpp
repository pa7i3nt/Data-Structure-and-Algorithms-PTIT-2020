#include <bits/stdc++.h>
using namespace std;
int n, k, s, arr[11], res = 0;

void result() {
    int sum = 0;
    for (int i = 1; i <= k; i++)
        sum += arr[i];
    if (sum == s)
        res++;
}

void Try(int i) {
    int j;
    for (j = arr[i-1] + 1; j <= n-k+i; j++) {
        arr[i] = j;
        if (i == k)
            result();
        else Try(i+1);
    }
}

int main() {
    int test_count = 100;
    do {
        cin >> n >> k >> s;
        res = 0;
        if (n == 0 && k == 0 && s == 0) {
            return 0;
        }
        else {
            Try(1);
            cout << res << endl;;
        }
    } while (test_count-- && n != 0 && k != 0 && s != 0);
    return 0;
}