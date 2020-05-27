#include <bits/stdc++.h>
using namespace std;

void selectionSort(int arr[], int n) {
    int i, j, min_index;
    int count = 1;

    for (i = 0; i < n - 1; i++) {
        min_index = i;
        for (j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_index])
                min_index = j;
        }
        if (min_index != i)
            swap(arr[i], arr[min_index]);

        cout << "Buoc " << count << ": ";
            for (int k = 0; k < n; k++)
                cout << arr[k] << " ";
        cout << endl;
        count++;
    }
}

int main() {
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    
    selectionSort(arr, n);

    return 0;
}