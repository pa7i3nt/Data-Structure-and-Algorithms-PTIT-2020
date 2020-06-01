#include <bits/stdc++.h>
using namespace std;

unordered_map <string, int> M;

void result(int n, string a, string b) {
    int i;
    M.clear();
    unordered_set <string> S;
    for (i = 0; i < n; i++) {
        string t;
        cin >> t;
        S.insert(t);
        M[t] = 0;
    }
    M[a] = 1;
    queue <string> q;
    q.push(a);
    string s1, s2;
    while (!q.empty()) {
        s1 = q.front();
        q.pop();
        if (s1 == b) {
            cout << M[s1] << endl;
            return;
        }

        for (i = 0; i < s1.length(); i++) {
            for (char c = 'A'; c <= 'Z'; c++) {
                s2 = s1;
                s2[i] = c;
                if (S.find(s2) != S.end() && M[s2] == 0) {
                    M[s2] = M[s1] + 1;
                    q.push(s2);
                }
            }
        }
    }
}

int main() {
    int t, n;
    string a, b;
    cin >> t;
    while (t--) {
        cin >> n;
        cin.ignore();
        cin >> a >> b;
        result(n, a, b);
    }
    return 0;
}