#include <bits/stdc++.h>
using namespace std;

void result(int arr[], int n) {
    int flag = 0, res;
    for (int i = 0; i < n - 1; i++) {
        if (arr[i] + 2 == arr[i + 1]) {
            flag++;
            res = arr[i] + 1;
            break;
        }
    }

    if (flag != 0)
        cout << res;
    else 
        cout << -1;
    
    cout << endl;
}

int main() {
    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        int arr[n - 1];
        for (int i = 0; i < n - 1; i++)
            cin >> arr[i];
        
        result(arr, n);
    }
    return 0;
}