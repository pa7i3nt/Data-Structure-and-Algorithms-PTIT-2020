#include <bits/stdc++.h>
using namespace std;

string s1, s2;

long long res(string str) {
    int tmp = 1, res = 0;
    for (int i = str.size() - 1; i >= 0; i--) {
        res += tmp * (int)(str[i] - '0');
        tmp *= 2;
    }
    return res;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        cin >> s1 >> s2;
        cout << res(s1) * res(s2) << endl;
    }
    return 0;
}