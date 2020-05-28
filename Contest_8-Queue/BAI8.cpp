#include <bits/stdc++.h>
using namespace std;

int mod(string tmp, int n) {
    int rem = 0;

    for (int i = 0; i < tmp.length(); i++) {
        rem = rem * 10 + (tmp[i] - '0');
        rem %= n;
    }

    return rem;
}

string result(int n) {
    queue <string> q;
    set <int> visit;

    string tmp = "1";
    q.push(tmp);

    while (!q.empty()) {
        tmp = q.front(); q.pop();

        int rem = mod(tmp, n);

        if (rem == 0)
            return tmp;
        
        else if (visit.find(rem) == visit.end()) {
            visit.insert(rem);
            q.push(tmp + "0");
            q.push(tmp + "1");
        }
    }
}

int main() {
    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        cout << result(n) << endl;
    }
    return 0;
}