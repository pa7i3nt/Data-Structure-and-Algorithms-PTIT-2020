#include <bits/stdc++.h>
using namespace std;

void SieveOfEratosthenes(long long n, bool isPrime[]) {
    isPrime[0] = isPrime[1] = false;
    for (long long i = 2; i <= n; i++)
        isPrime[i] = true;

    for (long long p = 2; p * p <= n; p++) {
        if (isPrime[p] == true) {
            for (long long i = p * p; i <= n; i += p)
                isPrime[i] = false;
        }
    }
}

void result(long long n) {
    int check = 0, i = 0;
    bool isPrime[n + 1];
    SieveOfEratosthenes(n, isPrime);

    for (i = 0; i < n; i++) {
        if (isPrime[i] && isPrime[n - i]) {
            check++;
            break;
        }
    }

    if (check != 0)
        cout << i << " " << n - i;
    else 
        cout << -1;
    
    cout << endl;
}

int main() {
    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        result(n);
    }
    return 0;
}