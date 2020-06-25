#include <bits/stdc++.h>
using namespace std;

int d[1000][1000], ce[1000][1000];
int n, m, k;

void floyd() {
    for (int k = 1; k <= n; k++) {
        for (int u = 1; u <= n; u++) {
            for (int v = 1; v <= n; v++) {
                if (d[u][v] > d[u][k] + d[k][v]) {
                    d[u][v] = d[u][k] + d[k][v];
                    ce[u][v] = ce[k][v];
                }
            }
        }
    }
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i == j)
                d[i][j] = 0;
            
            else d[i][j] = 1e9;

            ce[i][j] = i;
        }
    }

    for (int i = 1; i <= m; i++) {
        int u, v, c;
        cin >> u >> v >> c;
        d[u][v] = c;
        d[v][u] = c;
    }

    floyd();
    cin >> k;
    while (k--) {
        int u, v;
        cin >> u >> v;
        vector <int> sky;
        int x = v;
        sky.push_back(x);
        
        while (x != u) {
            x = ce[u][x];
            sky.push_back(x);
        }

        cout << d[u][v] << '\n';
    }
    return 0;
}