#include <bits/stdc++.h>
using namespace std;

int stop = 0, arr[17] = {0}, n, k;

void print() {
    int dem = 0;
    for (int i = 1; i <= n; i++)
        if (arr[i] == 1)
            dem++;
    
    if (dem == k) {
        for (int i = 1; i <= n; i++)
            cout << arr[i];
        cout << endl;
    }
}

void sinhkt() {
    int i = n;
    while (arr[i] == 1) {
        arr[i] = 0;
        i--;
    }
    if (i == 0)
        stop = 1;
    else arr[i] = 1;
}

int main() {
    int test_count;
    cin >> test_count;
    while (test_count--) {
        cin >> n >> k;
        stop = 0;
        while (!stop) {
            print();
            sinhkt();
        }
    }
    return 0;
}