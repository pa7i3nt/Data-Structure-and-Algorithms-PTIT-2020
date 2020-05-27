#include <bits/stdc++.h>
using namespace std;

int f[105];

// if i is even --> f[i] = min(f[i-1] + INSERT, f[i/2] + COPY)
// if i is odd -->  f[i] = min(f[i-1] + INSERT, f[(i + 1)/2] + COPY + DELETE)
// f[1] = INSERT

int result(int n, int INSERT, int DELETE, int COPY) {
    if (n == 1)
        return INSERT;

    f[1] = INSERT;

    for (int i = 2; i <= n; i++) {
        if (i % 2 == 0)
            f[i] = min(f[i - 1] + INSERT, f[i/2] + COPY);
        
        else 
            f[i] = min(f[i-1] + INSERT, f[(i + 1)/2] + COPY + DELETE);
    }

    return f[n];
}

int main() {
    int t, n, INSERT, DELETE, COPY;
    cin >> t;
    while (t--) {
        cin >> n >> INSERT >> DELETE >> COPY;
        cout << result(n, INSERT, DELETE, COPY) << endl;
    }
    return 0;
}