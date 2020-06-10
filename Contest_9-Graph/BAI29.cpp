#include <bits/stdc++.h>
using namespace std;

#define MAX 1005

int v, e;
bool chuaxet[MAX];
int truoc[MAX];
vector<int> arr[MAX];

void dfs(int u) {
    memset(chuaxet, true, sizeof(chuaxet));
    memset(truoc, 0, sizeof(truoc));

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
                truoc[y] = x;
                st.push(x);
                st.push(y);
                break;
            }
        }
    }
}

bool duongDi(int s, int t) {
    if (truoc[t] != 0)
        return true;
    
    return false;
}

bool bfs(int u) {
    vector<int> parent (v, -1);
    int i, x, y;
    memset(chuaxet, true, sizeof(chuaxet));

    queue<int> q;
    q.push(u);
    chuaxet[u] = false;

    while (!q.empty()) {
        x = q.front(); q.pop();
        for (i = 0; i < arr[x].size(); i++) {
            y = arr[x][i];
            if (chuaxet[y]) {
                chuaxet[y] = false;
                q.push(y);
                parent[y] = x;
            }

            else if (parent[x] != y)
                return true;
        }
    }

    return false;
}

bool result() {
    memset(chuaxet, true, sizeof (chuaxet));
    for (int i = 1; i <= v; i++)
        if (chuaxet[i] && bfs(i))
            return true;

    return false;
}

int main() {
    int test, s, t, tmp1, tmp2;
    cin >> test;
    while (test--) {
        vector <int> dinh;
        dinh.clear();

        for (int i = 0; i < MAX; i++)
            arr[i].clear();
        
        cin >> v >> e;

        for (int i = 0; i < e; i++) {
            cin >> tmp1 >> tmp2;
            arr[tmp1].push_back(tmp2);
            arr[tmp2].push_back(tmp1);
        }

        for (int i = 1; i <= v; i++) {
            if (arr[i].size() % 2 != 0)
                dinh.push_back(i);
        }

        s = dinh.front(); dinh.pop_back();
        t = dinh.front(); dinh.pop_back();

        cout << s << " " << t << endl;

        // dfs(s);
        // if (result())
        //     cout << "2\n";
        
        // else if (duongDi(s, t))
        //     cout << "1\n";

        // else cout << "0\n";
    }
    return 0;
}