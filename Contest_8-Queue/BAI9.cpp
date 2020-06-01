#include <bits/stdc++.h>
using namespace std;

void result(int s, int t) {
    int arr[20005], i;
    for (i = 0; i <= 20000; i++)
        arr[i] = INT_MAX;

    arr[s] = 0;
    queue <int> q; q.push(s);
    
    while (arr[t] == INT_MAX) {
        i = q.front(); q.pop();
        if (i - 1 > 0 && arr[i - 1] == INT_MAX) {
            arr[i - 1] = min(arr[i] + 1, arr[i - 1]);
            q.push(i - 1);
        }

        if (i * 2 < 20000 && arr[i * 2] == INT_MAX) {
            arr[i * 2] = min(arr[i] + 1, arr[i * 2]);
            q.push(i * 2);
        }
    }

    cout << arr[t] << endl;
}

int main() {
    int test, s, t;
    cin >> test;
    while (test--) {
        cin >> s >> t;
        result(s, t);
    }
    return 0;
}