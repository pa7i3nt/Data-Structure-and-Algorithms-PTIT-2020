#include <bits/stdc++.h>
using namespace std;

long long result(long long arr[], int n) {
    priority_queue<long long, vector<long long>,
                greater<long long> > pq(arr, arr + n);

    long long res = 0;

    while (pq.size() > 1) {
        long long first = pq.top();
        pq.pop();
        long long second = pq.top();
        pq.pop();

        res += first + second;
        pq.push(first + second);
    }

    return res;
}

int main() {
    int test, n;
    cin >> test;
    while (test--) {
        cin >> n;
        long long arr[n];
        for (int i = 0; i < n; i++)
            cin >> arr[i];

        cout << result(arr, n) << "\n";
    }
    return 0;
}