#include <bits/stdc++.h>
using namespace std;

int arr[100001], n;

void res() {
    sort(arr, arr + n);
    int mid = n / 2 + n % 2 - 1;
    int i = n - 1;
    int j = mid;
    int count = 0;
    
    while (mid < i && j >= 0) {
        if (arr[i] >= 2 * arr[j]) {
            count++;
            j--;
            i--;
        }
        else 
            j--;
    }
    cout << count + (n - 2 * count) << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        
        res();
    }
    return 0;
}