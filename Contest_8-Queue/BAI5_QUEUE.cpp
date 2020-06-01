// Test chay bang com
// 1
// 10 11
// 100 101 110 111
// 1000 1001 1010 1011 1100 1101 1110 1111

#include <bits/stdc++.h>
using namespace std;

void result(int n) {
    queue <string> q;
    q.push("1");

    while (n--) {
        string s1 = q.front();
        q.pop();
        cout << s1 << " ";

        string s2 = s1;

        q.push(s1.append("0"));
        q.push(s2.append("1"));
    }

    cout << endl;
}

int main() {
    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        result(n);
    }
    return 0;
}