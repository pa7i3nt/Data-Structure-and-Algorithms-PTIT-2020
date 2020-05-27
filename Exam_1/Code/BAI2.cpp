#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        long long n1, n2, n3;
        cin >> n1 >> n2 >> n3;
        long long a1[n1], a2[n2], a3[n3];
        for (long long i = 0; i < n1; i++) cin >> a1[i];
        for (long long i = 0; i < n2; i++) cin >> a2[i];
        for (long long i = 0; i < n3; i++) cin >> a3[i];

        long long i1 = 0, i2 = 0, i3 = 0, k;
        long long flag = 0, l = LLONG_MAX;
        while (i1 < n1 && i2 < n2 && i3 < n3) {
            if (a1[i1] == a2[i2] && a2[i2] == a3[i3]) {
                flag = 1;
                if (l != a1[i1]) {
                    cout << a1[i1] << " ";
                    l = a1[i1];
                }
                i1++;
                i2++;
                i3++;
            } else {
                k = min(a1[i1], min(a2[i2], a3[i3]));
                if (k == a1[i1]) i1++;
                if (k == a2[i2]) i2++;
                if (k == a3[i3]) i3++;
            }
        }
        if (!flag)
            cout << -1 << endl;
        else cout << endl;
    }
    return 0;
}