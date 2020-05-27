#include <bits/stdc++.h>
using namespace std;

void phanSo(long long tuso, long long mauso) {
    if (mauso == 0 || tuso == 0)
        return;

    if (mauso % tuso == 0) {
        cout << "1/" << (long long)(mauso / tuso) << endl;
        return;
    }

    if (tuso % mauso == 0) {
        cout << (long long)(tuso / mauso) << endl;
        return;
    }

    if (tuso > mauso) {
        cout << (long long)(tuso / mauso) << " + ";
        phanSo((long long)(tuso % mauso), mauso);
        return;
    }

    long long n = (long long)(mauso / tuso) + 1;
    cout << "1/" << n << " + ";

    phanSo((long long)(tuso * n) - mauso, (long long)(mauso * n));
}

int main() {
    int test;
    long long tuso, mauso;
    cin >> test;
    while (test--) {
        cin >> tuso >> mauso;
        phanSo(tuso, mauso);
    }
    return 0;
}