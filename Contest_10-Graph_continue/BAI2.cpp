#include <bits/stdc++.h>
using namespace std;

int n, m, check;
vector<int> vec[20];
bool chuaxet[20];

void halmiton(int u, int dem) {
    if (dem == n) {
        check = 1;
        return;
    }

    for (int i = 0; i < vec[u].size(); i++) {
        int v = vec[u][i];
        if (chuaxet[v]) {
            chuaxet[v] = false;
            halmiton(v, dem + 1);
            chuaxet[v] = true;
        }
    }
}

int main() {
    int t, i, u, v;
    cin >> t;
    while (t--) {
        for (i = 0; i < 20; i++)
            vec[i].clear();
        
        memset(chuaxet, true, sizeof(chuaxet));
        cin >> n >> m;
        for (i = 1; i <= m; i++) {
            cin >> u >> v;
            vec[u].push_back(v);
            vec[v].push_back(u);
        }

        check = 0;
        for (i = 1; i <= n; i++) {
            chuaxet[i] = false;
            halmiton(i, 1);
            chuaxet[i] = true;
        }

        cout << check << '\n';
    }
    return 0;
}