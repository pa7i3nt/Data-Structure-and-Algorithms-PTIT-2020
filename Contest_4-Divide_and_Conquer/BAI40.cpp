#include <bits/stdc++.h>
using namespace std;

int main() {
    int test, n;
    cin >> test;
    while (test--) {
        int result = 0;
        cin >> n;
        for (int i = 1; i <= n; i++) {
            int tmp;
            cin >> tmp;
            if (tmp == 0)
                result = i;
        }
        cout << result << endl;
    }
    return 0;
}