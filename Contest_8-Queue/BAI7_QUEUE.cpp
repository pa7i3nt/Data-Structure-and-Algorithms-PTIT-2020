#include <bits/stdc++.h>
using namespace std;

void result(long long n) {
    queue <long long> q;
    q.push(1);
    int res = 0;
    while (!q.empty()) {
        long long x = q.front();
        q.pop();
        if (x <= n) {
            res++;
            q.push(x * 10);
            q.push(x * 10 + 1);
        }
    }

    cout << res << endl;
}

int main() {
    int t;
    long long n;
    cin >> t;
    while (t--) {
        cin >> n;
        result(n);
    }
    return 0;
}