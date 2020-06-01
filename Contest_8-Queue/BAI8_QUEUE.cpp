#include <bits/stdc++.h>
using namespace std;

long long result(int n) {
    queue <long long> q;
    q.push(1);
    long long t = 0;
    while (!q.empty()) {
        t = q.front();
        q.pop();
        if (t % n == 0)
            return t;

        q.push(t * 10);
        q.push(t * 10 + 1);
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