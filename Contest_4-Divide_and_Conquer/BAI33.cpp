#include <bits/stdc++.h>
using namespace std;

#define MODULO 1000000007

long long power(long long n, long long k) {
    if (k == 0)
        return 1;

    long long x = power(n, (k / 2));

    if (k % 2 == 0)
        return x * x % MODULO;

    return n * (x * x % MODULO) % MODULO;
}

long long res(string str) {
    // calculate n^r
    long long n = stoll(str);
    reverse(str.begin(), str.end());
    long long r = stoll(str);
    return power(n, r);
}

int main() {
    int test;
    string str;
    cin >> test;
    while (test--) {
        cin >> str;
        cout << res(str) << "\n";
    }
    return 0;
}