#include <bits/stdc++.h>
using namespace std;

int d[] = {1, 10, 100, 1000};
int arr[10005];
bool prime[10005];

void sieve() {
    memset(prime, true, sizeof(prime));
    int i, j;
    prime[i] = false;

    for (i = 2; i <= 100; ++i)
        if (prime[i])
            for (j = 2; i * j <= 10000; prime[i*j++] = false);
}

int result(int s, int t) {
    queue <int> q;
    int arr[10005] = {0}, i, j, u, v;
    
    if (s == t)
        return 0;

    q.push(s);
    arr[s] = 1;
    while (!q.empty()) {
        u = q.front(); q.pop();
        for (i = 0; i < 4; ++i) {
            for (j = 0; j < 10; j++) {
                v = d[i] * ((u / d[i] / 10) * 10 + j) + u % d[i];

                if (v > 1000 && prime[v] && arr[v] == 0) {
                    q.push(v);
                    arr[v] = arr[u] + 1;
                    if (v == t)
                        return (arr[t] - 1);
                }
            }
        }
    }
    return -1;
}

int main() {
    int test, s, t;
    sieve();
    cin >> test;
    while (test--) {
        cin >> s >> t;
        cout << result(s, t) << endl;
    }
    return 0;
}