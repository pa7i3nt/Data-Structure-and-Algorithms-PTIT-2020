#include <bits/stdc++.h>
using namespace std;

int a[205], L[40005], n, s;

int kiemtra() {
    memset(L, 0, sizeof(L));
    int i, j;
    L[0] = 1;
    for (i = 1; i <= n; i++) {
        for (j = s; j >= a[i]; j--) {
            if(L[j] == 0 && L[j - a[i]] == 1)
                L[j] = 1;
        }
    }
    return L[s];
}

int main() {
    int t, i;
    cin >> t;
    while (t--) {
        cin >> n >> s;
        for (i = 1; i <= n; i++)
            cin >> a[i];
        if (kiemtra())
            cout << "YES" << endl;
        else 
            cout << "NO" << endl;
    }
}