#include <bits/stdc++.h>
using namespace std;

int stop = 0, arr[11], n;

void print() {
    for (int i = 1; i <= n; i++)
        cout << arr[i];
    cout << " ";
}

void sinhkt() {
    int i = n - 1, j, t;
    while (arr[i] > arr[i+1])
        i--;
    if (i == 0)
        stop = 1;
    else {
        j = n;
        while (arr[j] < arr[i])
            j--;
        t = arr[i]; arr[i] = arr[j]; arr[j] = t;

        int d = i + 1, c = n;
        while (d < c) {
            t = arr[d]; arr[d] = arr[c]; arr[c] = t;
            d++; c--;
        }
    }
}

int main() {
    int test_count;
    cin >> test_count;
    while (test_count--) {
        cin >> n;
        for (int i = 1; i <= n; i++)
            arr[i] = i;
        stop = 0;
        while (!stop) {
            print();
            sinhkt();
        }
        cout << endl;
    }
    return 0;
}