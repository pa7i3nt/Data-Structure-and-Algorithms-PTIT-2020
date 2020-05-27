#include <bits/stdc++.h>
using namespace std;

long long result(long long arr[], long long n) {
    vector<pair<long long, long long>> vec(n);
    for (long long i  = 0; i < n; ++i) {
        vec[i].first = arr[i];
        vec[i].second = i;
    }

    sort(vec.begin(), vec.end());

    long long res = 0;

    for (long long i = 0; i < n; ++i) {
        if (vec[i].second == i)
            continue;

        swap(vec[i].first, vec[vec[i].second].first);
        swap(vec[i].second, vec[vec[i].second].second);

        if (i != vec[i].second)
            --i;

        ++res;
    }

    return res;
}

int main() {
    int t;
    long long n;
    cin >> t;
    while (t--) {
        cin >> n;
        long long arr[n];
        for (long long i = 0; i < n; i++)
            cin >> arr[i];
        
        cout << result(arr, n) << endl;
    }
    return 0;
}