#include <bits/stdc++.h>
using namespace std;

vector<int> vec[15];
int color[15], n, m, d;

bool check(int u, int c) {
    for (int i = 0; i < vec[u].size(); i++)
        if (c == color[vec[u][i]])
            return false;
    
    return true;
}

bool result(int u) {
    if (u == n + 1)
        return true;

    for (int c = 1; c <= d; c++) {
        if (check(u, c)) {
            color[u] = c;
            if (result(u + 1))
                return true;
            
            color[u] = 0;
        }
    }
    return false;
}

int main() {
    int t, i, u, v;
    cin >> t;
    while (t--) {
        for (int i = 0; i < 15; i++)
            vec[i].clear();
        
        memset(color, 0, sizeof(color));
        cin >> n >> m >> d;

        for (i = 1; i <= m; i++) {
            cin >> u >> v;
            vec[u].push_back(v);
            vec[v].push_back(u);
        }

        if (result(1))
            cout << "YES\n";
        
        else 
            cout << "NO\n"; 
    }
    return 0;
}