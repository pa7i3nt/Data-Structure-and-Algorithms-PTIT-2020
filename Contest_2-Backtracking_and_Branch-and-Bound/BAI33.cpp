#include <bits/stdc++.h>
using namespace std;

int n, A[20], B[20] = {0};
int X[20] = {0}, N[20] = {0}, res = 0;
void in() {
    for (int i = 1; i <= n; i++)
        cout << A[i] << " ";
    cout << endl;
}


void kq() {
    res++;
}
void Try(int i) {
    int j;
    for (j = 1; j <= n; j++) {
        if (!B[j] && !X[i-j+n] && !N[i+j-1]) {
            // !B[j] : chua duoc chon
            A[i] = j;
            B[j] = 1;
            X[i-j+n] = 1;
            N[i+j-1] = 1;
            if (i == n)
                // in();
                kq();
            else Try(i+1);
            B[j] = 0;
            X[i-j+n] = 0;
            N[i+j-1] = 0;
        }
    }
}

int main() {
    cin >> n;
    Try(1);
    cout << res << endl;
    return 0;
}