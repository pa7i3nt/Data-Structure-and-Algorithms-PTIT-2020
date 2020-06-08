#include <bits/stdc++.h>
using namespace std;

#define MAX 1005

int v, e;
bool chuaxet[MAX];
vector<int> arr[MAX];

void bfs(int u) {
    int count = 0;
    memset(chuaxet, true, sizeof(chuaxet));

    int i, x, y;
    queue<int> q;

    if (u == 1) {
        q.push(2);
        chuaxet[2] = false;
    }

    else {
        q.push(1);
        chuaxet[1] = false;
    }

    chuaxet[u] = false;

    while (!q.empty()) {
        int x = q.front(); q.pop();
        count++;
        for (int i = 0; i < arr[x].size(); i++) {
            y = arr[x][i];
            if (chuaxet[y]) {
                chuaxet[y] = false;
                q.push(y);
            }
        }
    }
    
    if (count < (v - 1))
        cout << u << " ";
}

int main() {
    int t, tmp1, tmp2, flag;
    cin >> t;
    while (t--) {
        flag = 0;
        for (int i = 0; i < MAX; i++)
            arr[i].clear();
        
        cin >> v >> e;

        for (int i = 0; i < e; i++) {
            cin >> tmp1 >> tmp2;
            arr[tmp1].push_back(tmp2);
            arr[tmp2].push_back(tmp1);
        }

        for (int u = 1; u <= v; u++) {
            bfs(u);
        }
        cout << '\n';
    }
    return 0;
}