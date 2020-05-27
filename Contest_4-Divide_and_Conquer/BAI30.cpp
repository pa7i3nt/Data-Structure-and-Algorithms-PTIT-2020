#include <bits/stdc++.h>
using namespace std;

#define MODULO 1000000007

void nhanMaTran(long long A[2][2], long long B[2][2]) {
    long long x = A[0][0] * B[0][0] % MODULO + A[0][1] * B[1][0] % MODULO;
    long long y = A[0][0] * B[0][1] % MODULO + A[0][1] * B[1][1] % MODULO;
    long long z = A[1][0] * B[0][0] % MODULO + A[1][1] * B[1][0] % MODULO;
    long long t = A[1][0] * B[0][1] % MODULO + A[1][1] * B[1][1] % MODULO;
    
    A[0][0] = x;
    A[0][1] = y;
    A[1][0] = z;
    A[1][1] = t;
}

void power(long long A[2][2], long long n) {
    if (n == 0 || n == 1)
        return;
    
    long long B[2][2] = {{1, 1},
                         {1, 0}};
    
    power(A, n / 2);
    nhanMaTran(A, A);

    if (n % 2 != 0)
        nhanMaTran(A, B);
}

long long fib(long long n) {
    long long A[2][2] = {{1, 1},
                         {1, 0}};
    if (n == 0)
        return 0;
    
    power(A, n - 1);
    return A[0][0];
}

int main() {
    int test;
    long long n;
    cin >> test;
    while (test--) {
        cin >> n;
        cout << fib(n) % MODULO << "\n";
    }
    return 0;
}