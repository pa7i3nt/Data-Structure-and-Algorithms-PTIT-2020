#include <bits/stdc++.h>
using namespace std;

void display(int arr[], int n) {
    for (int i = 0; i < n; i++)
        cout << arr[i];
    cout << " ";
}

void findPermutations(int arr[], int n) {
    
    sort(arr, arr + n);

    reverse(arr, arr + n);

    do {
        display(arr, n);
    } while (prev_permutation(arr, arr + n));
}

int main() {
    int test_count, n;
    cin >> test_count;
    while (test_count--) {
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++)
            arr[i] = i + 1;

        findPermutations(arr, n);
        cout << endl;
    }
    return 0;
}