#include <bits/stdc++.h>
using namespace std;

int coins[] = {1, 2, 5, 10, 20, 50, 100, 200, 500, 1000};
int m = sizeof(coins) / sizeof(coins[0]);

void findMin(int vec) {
    vector<int> ans;
    int result = 0;

    for (int i = m - 1; i >= 0; i--) {
        while (vec >= coins[i]) {
            vec -= coins[i];
            ans.push_back(coins[i]);
        }
    }

    for (int i = 0; i < ans.size(); i++)
        result++;
    
    cout << result << "\n";
}

int main() {
    int test, n;
    cin >> test;
    while (test--) {
        cin >> n;
        findMin(n);
    }
    return 0;
}
