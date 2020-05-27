#include <bits/stdc++.h>
using namespace std;

int a[1005], c[1005], n;

int tinh() {
    int i, j, res = 1;
    for (i = 1; i <= n; i++) {
        c[i] = 1;
        for (j = 1; j < i; j++) {
            if (a[j] < a[i])
                c[i] = max(c[i], c[j] + 1);
        }
        res = max(res, c[i]);
    }
    return res;
}

int main() {
    int i;
    cin >> n;
    for (i = 1; i <= n; i++)
        cin >> a[i];
    cout << tinh() << endl;
}