#include <bits/stdc++.h>
using namespace std;

void result(int arr[], int n) {
    int i, dem0 = 0, dem1 = 0, dem2 = 0;
    for (i = 0; i < n; i++) {
        switch (arr[i])
        {
        case 0:
            dem0++;
            break;

        case 1:
            dem1++;
            break;

        case 2:
            dem2++;
            break;
        }
    }

    i = 0;

    while (dem0--)
        arr[i++] = 0;

    while (dem1--)
        arr[i++] = 1;

    while (dem2--)
        arr[i++] = 2;

    for (int j = 0; j < n; j++)
        cout << arr[j] << " ";
    cout << endl;
}

int main() {
    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        
        result(arr, n);
    }
    return 0;
}