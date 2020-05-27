#include <bits/stdc++.h>
using namespace std;

string s;
long long n;

char charAt(long long k, long long total) {
    if (k < s.length()) {
        return s[k];
    }
    if (k < total / 2) {
        return charAt(k, total / 2);
    }
    else {
        return charAt((k - 1) % (total / 2),
        total / 2);
    }
}

int main() {
    cin >> s >> n;
    long long i = s.length();
    while (i < n) {
        i *= 2;
    }
    cout << charAt(n-1, i);
    return 0;
}