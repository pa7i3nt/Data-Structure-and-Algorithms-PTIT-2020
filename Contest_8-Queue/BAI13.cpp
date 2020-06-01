#include <bits/stdc++.h>
using namespace std;

bool F[100005];
bool check(int n) {
    priority_queue <int> q;
    while (n) {
        q.push(n % 10);
        n /= 10;
    }

    if (!q.empty() && q.top() > 5)
        return false;
    
    else {
        while (!q.empty()) {
            int temp = q.top();
            q.pop();
            if (!q.empty() && q.top() == temp)
                return false;
        }
    }

    return true;
}

int main() {
    int t, L, R, i, d;

    for (i = 0; i <= 100000; i++)
        F[i] = check(i);

    cin >> t;
    while (t--) {
        cin >> L >> R;
        d = 0;
        for (i = L; i <= R; i++)
            if (F[i] == 1)
                d++;

        cout << d << endl;
    }
    return 0;
}