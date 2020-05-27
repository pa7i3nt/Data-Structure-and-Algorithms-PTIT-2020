#include <bits/stdc++.h>
using namespace std;

void printFirst(int n, int arr[]) {
    cout << "[";
    for (int i = 1; i <= n; i++) {
        if (i == n)
            cout << arr[i];
        else 
            cout << arr[i] << " ";
    }
    cout << "]" << endl;
}

void triangle(int n, int arr[]) {
    int row = n - 1;
    while (row > 0) {
        for (int i = 1; i <= row; i++) {
            arr[i] = arr[i] + arr[i+1];
        }
        cout << "[";
        for (int i = 1; i <= row; i++) {
            if (i == row)
                cout << arr[i];
            else 
                cout << arr[i] << " ";
        }
        cout << "]" << endl;
        row--;
    }
}

int main() {
    int test_count, n;
    cin >> test_count;
    while (test_count--) {
        cin >> n;
        int arr[n];
        for (int i = 1; i <= n; i++)
            cin >> arr[i];
        printFirst(n, arr);
        triangle(n, arr);
    }
    return 0;
}