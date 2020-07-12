#include <bits/stdc++.h>
using namespace std;

const int MAX = 2 * 1E5;
vector < pair < int, int > > graph[MAX + 5];
priority_queue < pair < int, int >, vector < pair < int, int > >,
                greater < pair < int, int > > > min_heap;

long long ans = 0;
bool mark[MAX + 5];

void prim() {
    min_heap.push(make_pair(0, 1));
    while (!min_heap.empty()) {
        int u = min_heap.top().second;
        int min_cost = min_heap.top().first;
        min_heap.pop();

        if (mark[u])
            continue;
        
        mark[u] = true;
        ans += min_cost;
        for (int i = 0; i < graph[u].size(); i++) {
            int v = graph[u][i].second;
            int cost = graph[u][i].first;
            if (!mark[v])
                min_heap.push(make_pair(cost, v));
        }
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        for (int i = 1; i <= n; i++)
            graph[i].clear();
        
        memset(mark, false, sizeof(mark));

        while (!min_heap.empty())
            min_heap.pop();
        
        while (m-- ) {
            int u, v, c;
            cin >> u >> v >> c;
            graph[u].push_back(make_pair(c, v));
            graph[v].push_back(make_pair(c, u));
        }

        ans = 0;
        prim();
        cout << ans << '\n';
    }

    return 0;
}