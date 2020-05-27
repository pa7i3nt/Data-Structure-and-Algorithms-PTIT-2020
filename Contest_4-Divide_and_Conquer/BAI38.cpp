#include <bits/stdc++.h>
using namespace std;

long long search(long long m, long long n,
                 long long A[], long long B[], long long k) {
    long long all = m + n;
    long long C[all];

    for (long long i = 0; i < m; i++)
        C[i] = A[i];
    for (long long i = 0, j = m; i < n; i++, j++)
        C[j] = B[i];

    sort(C, C + all);

    return C[k-1];
}

int main() {
    int test;
    long long m, n, k;
    cin >> test;
    while (test--) {
        cin >> m >> n >> k;
        long long A[m], B[n];
        for (long long i = 0; i < m; i++)
            cin >> A[i];
        for (long long j = 0; j < n; j++)
            cin >> B[j];
        cout << search(m, n, A, B, k) << "\n";
    }
    return 0;
}