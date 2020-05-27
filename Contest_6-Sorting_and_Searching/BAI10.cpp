#include <bits/stdc++.h>
using namespace std;

void res(int arr[], int n) {
    vector<int> number;
    int tmp = 0;
    for (int i = 0; i < n; i++) {
        tmp = 0;
        while (arr[i] > 0) {
            tmp = arr[i] % 10;
            arr[i] /= 10;
            number.push_back(tmp);
        }
    }

    vector<int>::iterator ip;
    stable_sort(number.begin(), number.end());

    ip = std::unique(number.begin(), number.begin() + number.size());
    number.resize(std::distance(number.begin(), ip));

    for (ip = number.begin(); ip != number.end(); ++ip)
        cout << *ip << " ";
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
        
        res(arr, n);
    }
    return 0;
}