#include <bits/stdc++.h>
using namespace std;

// Gop 2 mang con vao mang arr[]
// Mang 1: arr[left..mid]
// Mang 2: arr[mid+1..right]
void mergeArray(int arr[], int left, int mid, int right) {
    int i, j, k;
    int n1 = mid - left + 1;
    int n2 = right - mid;

    // Temp arrays
    int LEFT[n1], RIGHT[n2];

    // Copy du lieu vao 2 temp arrays
    for (i = 0; i < n1; i++)
        LEFT[i] = arr[left + i];

    for (j = 0; j < n2; j++)
        RIGHT[j] = arr[mid + 1 + j];

    /* Gop 2 temp arrays tro lai mang ban dau arr[left..right]; */
    i = 0;      // bien dem cua mang LEFT
    j = 0;      // bien diem cua mang RIGHT
    k = left;   // bien dem cua mang da gop 

    while (i < n1 && j < n2) {
        if (LEFT[i] <= RIGHT[j]) {
            arr[k] = LEFT[i];
            i++;
        }
        else {
            arr[k] = RIGHT[j];
            j++;
        }
        k++;
    }

    /* Copy nhung phan tu con lai cua mang LEFT (neu co) */
    while (i < n1) {
        arr[k] = LEFT[i];
        i++;
        k++;
    }

    /* Copy nhung phan tu con lai cua mang RIGHT (neu co) */
    while (j < n2) {
        arr[k] = RIGHT[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        // Gia tri tuong tu (left + right) / 2
        // Bieu thuc de de tranh truong hop overflow
        // doi voi large left and right
        int mid = left + (right - left) / 2;

        // Sort 2 subarrays
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        mergeArray(arr, left, mid, right);
    }
}

int main() {
    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        
        mergeSort(arr, 0, n - 1);

        for (int i = 0; i < n; i++)
            cout << arr[i] << " ";
        cout << endl;
    }
    return 0;
}