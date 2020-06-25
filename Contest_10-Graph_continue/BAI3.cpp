#include <bits/stdc++.h>
using namespace std;

vector<int> vec[1005];
int color[1005], n, m;
bool chuaxet[1005], check;

void dfs(int u, int t) {
    chuaxet[u] = false;
    for (int i = 0; i < vec[u].size(); i++) {
        int v = vec[u][i];
        if (chuaxet[v]) {
            if (color[v] == 0)
                color[v] = 3 - color[u];
            
            dfs(v, u);
        }
    }
}

int main() {
    int t, i, j, u, v;
    cin >> t;
    while (t--) {
        for (i = 1; i <= 1005; i++)
            vec[i].clear();
        
        memset(color, 0, sizeof(color));
        memset(chuaxet, true, sizeof(chuaxet));
        cin >> n >> m;

        for (i = 1; i <= m; i++) {
            cin >> u >> v;
            vec[u].push_back(v);
            vec[v].push_back(u);
        }

        for (i = 1; i <= n; i++) {
            if (color[i] == 0) {
                color[i] = 1;
                dfs(i, 0);
            }
        }

        check = true;
        for (i = 1; i <= n; i++) {
            for (j = 0; j < vec[i].size(); j++) {
                if (color[i] == color[vec[i][j]])
                    check = false;
            }
        }

        if (check)
            cout << "YES\n";
        
        else cout << "NO\n";
    }
    return 0;
}