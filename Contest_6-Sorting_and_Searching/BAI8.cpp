#include <bits/stdc++.h>
using namespace std;

int countEachElementOfArr1(int x, int arr2[], int m, int demSo0[]) {
    if (x == 0)
        return 0;

    if (x == 1)
        return demSo0[0];

    int* index = upper_bound(arr2, arr2 + m, x);
    int ans = (arr2 + m) - index;

    ans += (demSo0[0] + demSo0[1]);

    if (x == 2)
        ans -= (demSo0[3] + demSo0[4]);
    
    if (x == 3)
        ans += demSo0[2];

    return ans;
}

int result(int arr1[], int arr2[], int n, int m) {
    int demSo0[5] = {0};

    for (int i = 0; i < m; i++)
        if (arr2[i] < 5)
            demSo0[arr2[i]]++;

    stable_sort(arr2, arr2 + m);

    int res = 0;

    for (int i = 0; i < n; i++)
        res += countEachElementOfArr1(arr1[i], arr2, m, demSo0);

    return res;
}

int main() {
    int t, n, m;
    cin >> t;
    while (t--) {
        cin >> n >> m;

        int arr1[n], arr2[m];

        for (int i = 0; i < n; i++)
            cin >> arr1[i];
        
        for (int j = 0; j < m; j++)
            cin >> arr2[j];

        cout << result(arr1, arr2, n, m) << endl;
    }
    return 0;
}