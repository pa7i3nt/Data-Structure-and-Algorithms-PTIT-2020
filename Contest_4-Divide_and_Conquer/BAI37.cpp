#include <bits/stdc++.h>
using namespace std;

long long res(long long arr[], long long left, 
                long long right, long long x)
{
    if (left > right)
        return -1;
    
    // Neu phan tu cuoi cung nho hon x
    if (x >= arr[right])
        return right;

    int mid = (left + right) / 2;

    // Neu mid la diem thoa man
    if (arr[mid] == x)
        return mid;

    // Neu x nam giua mid - 1 va mid
    if (mid > 0 && arr[mid-1] <= x && x < arr[mid])
        return mid - 1;

    if (x < arr[mid])
        return res(arr, left, mid - 1, x);

    return res(arr, mid + 1, right, x);
}

int main() {
    int test;
    long long n, x;
    cin >> test;
    while (test--) {
        cin >> n >> x;
        long long arr[n];
        for (long long i = 0; i < n; i++)
            cin >> arr[i];
        
        long long ans = res(arr, 0, n - 1, x);
        if (ans != -1)
            cout << ans + 1 << "\n";
        else 
            cout << ans << "\n";
    }
    return 0;
}