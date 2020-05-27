#include <bits/stdc++.h>
using namespace std;
int n, k, B[20], arr[20];
bool printed = false;

void in() {
    int i, t = 0;
    for (i = 0; i < n; i++)
        t += arr[i] * B[i];
    if (t == k) {
        cout << "[";
        for (i = 0; i < n; i++)
            if (B[i] == 1)
                cout << arr[i] << " ";

        // cout << "\b] ";
        cout << "] ";
        printed = true;
    }
}

void Try(int i) {
    int j;
    for (j = 1; j >= 0; j--) {
        B[i] = j;
        if (i == n - 1)
            in();
        else Try(i+1);
    }
}

int main() {
    int test_count;
    cin >> test_count;
    while (test_count--) {
        cin >> n >> k;
        for (int i = 0; i < n; i++)
            cin >> arr[i];

        printed = false;
        sort(arr, arr + n);
        
        Try(0);
        if (printed == false)
            cout << "-1";
        
        cout << endl;
    }
    return 0;
}