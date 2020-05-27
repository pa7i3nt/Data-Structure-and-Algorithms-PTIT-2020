#include <bits/stdc++.h>
using namespace std;

int C[1005][1005], n, k;
int M = 1e9 + 7;
void tinh() {
    int i, j;
    // Cong thuc tam giac pascal
    for (i = 0; i <= 1000; i++) {
        for (j = 0; j <= i; j++) {
            if (j == 0 || j == i)
                C[i][j] = 1;
            else 
                C[i][j] = (C[i-1][j] + C[i-1][j-1]) % M;
        }
    }
}

int main() {
    int test;
    // Tinh 1 lan de dung cho toan bo test case
    tinh();
    cin >> test;
    while (test--) {
        cin >> n >> k;
        cout << C[n][k] << endl;
    }
    return 0;
}