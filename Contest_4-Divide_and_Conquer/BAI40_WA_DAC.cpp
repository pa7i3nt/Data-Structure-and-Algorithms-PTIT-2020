#include <bits/stdc++.h>
using namespace std;

// Neu so 0 xuat hien trong arr, tra ve gia tri la
// vi tri dau tien xuat hien so 0 trong arr[left...right]
// nguoc lai tra ve gia tri -1
int search(int arr[], int left, int right) {
    if (right >= left) {
        int mid = (left + right) / 2;

        if ((mid == 0 || arr[mid-1] == 1) && arr[mid] == 0)
            return mid;

        // Neu gia tri tai vi tri mid khong phai 0
        if (arr[mid] == 1)
            return search(arr, mid + 1, right);

        // Neu gia tri tai vi tri mid la 0,
        // nhung khong phai la gia tri 0 dau tien
        else
            return search(arr, left, mid - 1);
    }
    return -1;
}

int res(int arr[], int n) {
    int tmp = search(arr, 0, n - 1);

    if (tmp == -1)
        return 0;
    
    return (n - tmp);
}

int main() {
    int test, n;
    cin >> test;
    while (test--) {
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        
        cout << res(arr, n) << "\n";
    }
    return 0;
}