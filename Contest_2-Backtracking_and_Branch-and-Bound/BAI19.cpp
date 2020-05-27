#include <bits/stdc++.h>
using namespace std;

int arr[20], n;

void fact(int n) {
    int i;
    if (n == 0)
        return;
    cout << "[";
    for (i = 1; i < n; i++)
        cout << arr[i] << " ";
    cout << arr[n] << "]" << endl;
    for (i = 1; i <= n; i++)
        arr[i] = arr[i] + arr[i+1];
    // n--;
}

int main() {
    int test_count;
    cin >> test_count;
    while (test_count--) {
        cin >> n;
        for (int i = 1; i <= n; i++)
            cin >> arr[i];
        while(n > 0) {
            fact(n);
            n--;
        }
    }
    return 0;
}