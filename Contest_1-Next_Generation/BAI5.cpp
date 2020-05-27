#include <bits/stdc++.h>
using namespace std;

int stop = 0, arr[16], n, k;

void print() {
    for (int i = 1; i <= k; i++)
        cout << arr[i];
    cout << " ";
}

void sinhkt() {
    int i = k, j;
    while (arr[i] == n - k + i)
        i--;
    if (i == 0)
        stop = 1;
    else {
        arr[i]++;
        for (j = i + 1; j <= k; j++)
            arr[j] = arr[j-1] + 1;
    }
}

int main() {
    int test_count;
    cin >> test_count;
    while (test_count--) {
        cin >> n >> k;
        for (int i = 1; i <= k; i++)
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