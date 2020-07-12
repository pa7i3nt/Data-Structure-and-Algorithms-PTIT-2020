#include <bits/stdc++.h>
using namespace std;

#define MAX 10005

bool chuaxet[MAX];
vector<int> arr[MAX];
int CBT[MAX][2], sc = 0, v, e;

void dfs(int u) {
    chuaxet[u] = false;

    if (sc == e - 1)
        return;
    
    for (int i = 0; i < arr[u].size(); i++) {
        int k = arr[u][i];
        if (chuaxet[k]) {
            sc++;
            CBT[sc][1] = u;
            CBT[sc][2] = k;

            if (sc == e - 1)
                return;
            
            else dfs(k);
        }
    }
}

void result() {
    int i, j;
    for (i = 1; i <= sc; i++) {
        for (j = 1; j <= 2; j++) {
            cout << CBT[i][j] << " ";
        }
        cout << '\n';
    }
}

int main() {
    int t, u, tmp1, tmp2;
    cin >> t;
    while (t--) {
        sc = 0;
        for (int i = 0; i < MAX; i++)
            arr[i].clear();
        
        cin >> v >> e >> u;

        for (int i = 0; i < e; i++) {
            cin >> tmp1 >> tmp2;
            arr[tmp1].push_back(tmp2);
            arr[tmp2].push_back(tmp1);
        }

        memset(chuaxet, true, sizeof(chuaxet));
        dfs(u);

        cout << sc << '\n';

        if (sc < (e - 1))
            cout << "-1\n";
        
        else 
            result();
    }
    return 0;
}