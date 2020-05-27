#include <bits/stdc++.h>
using namespace std;

int f[105][105];

int result(string s) {
    int len = s.size();
    for (int i = 1; i <= len; i++) {
        for (int j = 1; j <= len; j++) {
            if (i != j && s[i - 1] == s[j - 1])
                f[i][j] = f[i - 1][j - 1] + 1;
            else
                f[i][j] = max(f[i - 1][j], f[i][j - 1]);
        }
    }
    return f[len][len];
}

int main() {
    int t, n;
    string s;
    cin >> t;
    while (t--) {
        cin >> n;
        cin >> s;
        cout << result(s) << endl;
    }
    return 0;
}