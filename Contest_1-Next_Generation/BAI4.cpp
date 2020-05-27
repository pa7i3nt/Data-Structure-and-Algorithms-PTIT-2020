#include <bits/stdc++.h>
using namespace std;

int stop = 0, n;
char arr[10];

void print() {
    for (int i = 1; i <= n; i++)
        cout << arr[i];
    cout << " ";
}

void sinhkt() {
    int i = n;
    while (arr[i] == 'B') {
        arr[i] = 'A';
        i--;
    }
    if (i == 0)
        stop = 1;
    else arr[i] = 'B';
}

int main() {
    int test_count;
    cin >> test_count;
    while (test_count--) {
        cin >> n;
        for (int i = 1; i <= n; i++)
            arr[i] = 'A';
        stop = 0;
        while (!stop) {
            print();
            sinhkt();
        }
        cout << endl;
    }
    return 0;
}