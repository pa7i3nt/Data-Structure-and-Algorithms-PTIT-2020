#include <bits/stdc++.h>
using namespace std;

int result(int n) {
    set <int> visit;
    int i;
    queue<pair<int, int> > q;
    q.push({n, 0});
    visit.insert(n);

    while (!q.empty()) {
        pair <int, int> t = q.front(); q.pop();

        if (t.first == 1)
            return t.second;

        if (t.first - 1 == 1)
            return t.second + 1;

        if (visit.find(t.first - 1) == visit.end()) {
            q.push({t.first - 1, t.second + 1});
            visit.insert(t.first - 1);
        }

        for (i = 2; i * i <= (t.first); i++) {
            if (t.first % i == 0) {
                if (visit.find(t.first / i) == visit.end()) {
                    q.push({t.first / i, t.second + 1});
                    visit.insert(t.first / i);
                }
            }
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