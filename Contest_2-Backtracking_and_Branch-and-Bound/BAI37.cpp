#include <bits/stdc++.h>
using namespace std;

int res = 1, test = 1;
int n, m, mat[30][30], ans = -1;

void dfs(int u, int temp) {
    ans = max(ans, temp);

    for (int i = 0; i < n; i++) {
        if (mat[u][i] == 1) {
            mat[u][i] = 0;
            mat[i][u] = 0;

            dfs(i, temp + 1);

            mat[u][i] = 1;
            mat[i][u] = 1;
        }
    }
}

void init() {
    cin >> n >> m;
    int a, b;
    memset(mat, 0, sizeof(mat));

    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        mat[a][b] = 1;
        mat[b][a] = 1;
    }
}

void result() {
    ans = -1;
    for (int i = 0; i < n; i++)
        dfs(i, 0);

    cout << ans << endl;
}

int main() {
    int test;
    cin >> test;
    while (test--) {
        init();
        result();
    }
    return 0;
}