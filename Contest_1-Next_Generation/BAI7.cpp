#include <bits/stdc++.h>
using namespace std;

int stop = 0, arr[11], n, dem, k;

void init() {
    cin >> n;
    k = 1;
    dem = 0;
    arr[k] = n;
}
void print() {
    cout << '(';
    for (int i = 1; i <= k; i++) {
        if (i < k)
            cout << arr[i] << " ";
        else 
            cout << arr[i];
    }
    cout << ") ";
}

void phanTichSo() {
    int i, j, R, S, D;
    i = k;
    while (i > 0 && arr[i] == 1)
        i--;
    if (i > 0) {
        arr[i] = arr[i] - 1;
        D = k - i + 1;
        R = D / arr[i];
        S = D % arr[i];
        k = i;
        if (R > 0) {
            for (j = i + 1; j <= i + R; j++)
                arr[j] = arr[i];
            k = k + R;
        }
        if (S > 0) {
            k = k + 1;
            arr[k] = S;
        }
    }
    else 
        stop = 1;
}

int main() {
    int test_count;
    cin >> test_count;
    while (test_count--) {
        init();
        stop = 0;
        while (!stop) {
            print();
            phanTichSo();
        }
        cout << endl;
    }
    return 0;
}