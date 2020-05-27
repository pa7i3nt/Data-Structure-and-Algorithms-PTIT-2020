#include <bits/stdc++.h>
using namespace std;

string s;

long long result() {
    long long tmp = (int)(s[0] - '0');
    long long res = tmp;

    for (int i = 1; i < s.size(); i++) {
        tmp = (i + 1) * (int)(s[i] - '0') + 10 * tmp;
        res += tmp;
    }
    return res;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        cin >> s;
        cout << result() << endl;
    }
    return 0;
}