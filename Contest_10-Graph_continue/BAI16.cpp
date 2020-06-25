#include <bits/stdc++.h>
using namespace std;

using namespace std;

double cost[105][105];
int n;
double ans = 0;
bool mark[105];

struct Edge {
    int u, v;
    double cost;
    Edge() {}
    Edge(int U, int V, double C) {
        u = U;
        v = V;
        cost = C;
    }
};

vector <Edge> edge;
int par[105];

double dist(pair < double, double > a, pair < double, double > b) {
    return sqrt((a.first - b.first) * (a.first - b.first)
                + (a.second - b.second) * (a.second - b.second));
}

bool cmp(Edge u, Edge v) {
    return u.cost < v.cost;
}

int root(int x) {
    while (par[x] > 0)
        x = par[x];
    
    return x;
}

void merge(int x, int y) {
    x = root(x);
    y = root(y);
    if (x == y)
        return;
    
    if (par[x] < par[y]) {
        par[x] += par[y];
        par[y] = x;
    }

    else {
        par[y] += par[x];
        par[x] = y;
    }
}

void kruskal() {
    sort(edge.begin(), edge.end(), cmp);
    for (int i = 0; i < edge.size(); i++) {
        int u = root(edge[i].u);
        int v = root(edge[i].v);
        if (u != v) {
            merge(u, v);
            ans += edge[i].cost;
        }
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        cin >> n;
        memset(par, -1, sizeof(par));
        vector < pair < double, double > > a(n + 5);
        for (int i = 1; i <= n; i++)
            cin >> a[i].first >> a[i].second;
        
        edge.clear();
        for (int i = 1; i < n; i++) {
            for (int j = i + 1; j <= n; j++) {
                cost[i][j] = dist(a[i], a[j]);
                edge.push_back(Edge(i, j, cost[i][j]));
            }
        }

        ans = 0;
        kruskal();
        cout << fixed << setprecision(6) << ans << '\n';
    }
    return 0;
}