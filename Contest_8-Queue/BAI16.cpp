#include <bits/stdc++.h>
using namespace std;

int a[20], b[20];
map <string, int> M;
queue <string> Q, P;

int d1[7] = {0, 1, 5, 2, 4, 6, 3};
int d2[7] = {0, 4, 1, 3, 5, 2, 6};

string process1(string u) {
    u = '0' + u;
    string s = "";
    for (int i = 1; i <= 6; i++)
        s += u[d1[i]];
    
    return s;
}

string process2(string u) {
    u = '0' + u;
    string s = "";
    for (int i = 1; i <= 6; i++)
        s += u[d2[i]];

    return s;
}

void solve() {
    int i, d = 0;
    string ST = "", EN = "";
    for (i = 1; i <= 6; i++)
        ST += (char)(a[i] + 48);
    
    for (i = 1; i <= 6; i++)
        EN += (char)(b[i] + 48);
    
    M[ST] = 1;
    Q.push(ST);

    while (!Q.empty()) {
        string u = Q.front(); Q.pop();
        if (u == EN) {
            d = M[EN];
            cout << d - 1 << endl;
            return;
        }

        string tmp = "";
        tmp = process1(u);
        if (M.find(tmp) == M.end()) {
            M[tmp] = M[u] + 1;
            Q.push(tmp);
        }

        tmp = process2(u);
        if (M.find(tmp) == M.end()) {
            M[tmp] = M[u] + 1;
            P.push(tmp);
        }
    }
}

int main() {
    string x;
    for (int i = 0; i < 6; i++) {
        cin >> x;
        Q.push(x);
    }
    
    for (int i = 0; i < 6; i++) {
        cin >> x;
        P.push(x);
    }

    solve();
    return 0;
}