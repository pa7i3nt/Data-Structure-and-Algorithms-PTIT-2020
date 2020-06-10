#include <bits/stdc++.h>
using namespace std;

#define MAX 505

typedef pair <int, int> pii;
int t, n, m, res;
int arr[MAX][MAX];
int dx[] = {-1, -1, -1, 0, 1, 1, 1, 0};
int dy[] = {-1, 0, 1, 1, 1, 0, -1, -1};

bool check(int a, int b) {
    if (a < 1 || a > n || b < 1 || b > m)
        return false;
    
    return true;
}

void bfs(pii s) {
    queue <pii> q;
    q.push(s);
    arr[s.first][s.second] = 0;
    while (!q.empty()) {
        pii k = q.front();
        q.pop();
        for (int i = 0; i < 8; i++) {
            int x = k.first + dx[i];
            int y = k.second + dy[i];
            if (check(x, y) && arr[x][y] == 1) {
                q.push(pii(x, y));
                arr[x][y] = 0;
            }
        }
    }
}

int main() {
    cin >> t;
    while (t--) {
        cin >> n >> m;
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++)
                cin >> arr[i][j];

        res = 0;

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (arr[i][j] == 1) {
                    res++;
                    bfs(pii(i, j));
                }
            }
        }

        cout << res << '\n';
    }
    return 0;
}