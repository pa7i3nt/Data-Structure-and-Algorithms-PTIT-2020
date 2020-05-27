#include <bits/stdc++.h>
using namespace std;

void result(long long arr1[], long long arr2[], int n, int m) {
    vector<long long> number;

    for (int i = 0; i < n; i++)
        number.push_back(arr1[i]);

    for (int j = 0; j < m; j++)
        number.push_back(arr2[j]);
    
    vector<long long>::iterator ip;
    sort(number.begin(), number.end());

    // ip = std::unique(number.begin(), number.begin() + number.size());
    // number.resize(std::distance(number.begin(), ip));

    for (ip = number.begin(); ip != number.end(); ++ip)
        cout << *ip << " ";
    cout << endl;
}

int main() {
    int t, n, m;
    cin >> t;
    while (t--) {
        cin >> n >> m;
        long long arr1[n], arr2[m];
        for (int i = 0; i < n; i++)
            cin >> arr1[i];

        for (int j = 0; j < m; j++)
            cin >> arr2[j];

        result(arr1, arr2, n, m);
    }
    return 0;
}