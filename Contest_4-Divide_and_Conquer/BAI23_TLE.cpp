#include <bits/stdc++.h>
using namespace std;

long long power(long long n, long long k) {
    if (k == 0)
        return 1;

    long long x = power(n, k / 2);

    if (k % 2 == 0)
        return x * x;

    return n * x * x;
}

int binarySearch(vector<long long> arr, long long left, long long right, long long k) {
    if (left > right)
        return 0;
    else {
        long long mid = (left + right) / 2;
        if (arr[mid] == k)
            return mid;

        if (arr[mid] > k)
            return binarySearch(arr, left, mid - 1, k);

        return binarySearch(arr, mid + 1, right, k);
    }
}

void solution(long long n, long long k) {
    long long new_size = 1;
    vector<long long> arr(1);
    arr.at(0) = 1;
    // for (int i = 0; i < arr.size(); i++)
    //     cout << arr[i] << " ";
    // cout << endl;
    if (n == 1 && k == 1)
        cout << 1 << endl;
    else {
        for (long long i = 1; i < n; i++) {
            new_size = 2 * new_size + 1;
            long long mid = new_size / 2;
            arr.resize(new_size);
            arr[mid] = i + 1;
            for (int i = 0, j = arr.size() - 1; i < mid; i++, j--)
                arr[j] = arr[i];

            // for (int i = 0; i < arr.size(); i++)
            //     cout << arr[i] << " ";
            // cout << endl;
        }
    }

    cout << arr[k-1] << endl;
}

int main() {
    int test;
    long long n, k;
    cin >> test;
    while (test--) {
        cin >> n >> k;
        solution(n, k);
    }
    return 0;
}