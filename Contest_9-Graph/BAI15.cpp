#include <bits/stdc++.h>
using namespace std;

#define MAX 1005

bool chuaxet[MAX];
vector<int> arr[MAX];

void dfs(int u) {
    // memset(chuaxet, true, sizeof(chuaxet));

    int i, x, y;
    stack<int> st;
    st.push(u);
    chuaxet[u] = false;

    while (!st.empty()) {
        x = st.top(); st.pop();
        for (i = 0; i < arr[x].size(); i++) {
            y = arr[x][i];
            if (chuaxet[y]) {
                chuaxet[y] = false;
                st.push(x);
                st.push(y);
                break;
            }
        }
    }
}

int main() {
    int t, v, e, tmp1, tmp2, u;
    cin >> t;
    while (t--) {
        memset(chuaxet, true, sizeof(chuaxet));
        int res = 0;
        for (int i = 0; i < MAX; i++)
            arr[i].clear();
        
        cin >> v >> e;

        for (int i = 0; i < e; i++) {
            cin >> tmp1 >> tmp2;
            arr[tmp1].push_back(tmp2);
            arr[tmp2].push_back(tmp1);
        }

        for (u = 1; u <= v; u++) {
            if (chuaxet[u]) {
                res++;
                dfs(u);
            }
        }

        cout << res << '\n';
    }
    return 0;
}