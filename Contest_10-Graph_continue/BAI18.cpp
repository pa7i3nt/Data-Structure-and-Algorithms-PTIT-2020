#include <bits/stdc++.h>
using namespace std;

const int MAX = 1e5;
vector < pair < int, int > > graph[MAX + 5];
priority_queue < pair < long long, long long >,
        vector < pair < long long, long long > >,
        greater < pair < long long, long long > > > min_heap;
    
long long dist[MAX + 5];
long long f[MAX + 5];
int n, m;

void init() {
    for (int i = 1; i <= n; i++) {
        dist[i] = 1e12;
    }

    dist[1] = 0;
    f[1] = 1;
}

void dijkstra(int u) {
    min_heap.push(make_pair(0, u));
    while (!min_heap.empty()) {
        long long min_cost = min_heap.top().first;
        int u = min_heap.top().second;
        min_heap.pop();
        for (int i = 0; i < graph[u].size(); i++) {
            int v = graph[u][i].first;
            if (dist[v] == min_cost + graph[u][i].second) {
                f[v] += f[u];
                continue;
            }

            if (dist[v] > min_cost + graph[u][i].second) {
                dist[v] = min_cost + graph[u][i].second;
                f[v] = f[u];
                min_heap.push(make_pair(dist[v], v));
            }
        }
    }
}

int main() {
    cin >> n >> m;
    while (m--) {
        int u, v, c;
        cin >> u >> v >> c;
        graph[u].push_back(make_pair(v, c));
        graph[v].push_back(make_pair(u, c));
    }

    init();
    dijkstra(1);
    cout << dist[n] << " " << f[n];

    return 0;
}