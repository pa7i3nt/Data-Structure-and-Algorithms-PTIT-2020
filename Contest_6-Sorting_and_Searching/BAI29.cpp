#include <bits/stdc++.h>
using namespace std;

void bubbleSort(int arr[], int n) {
    int count = 1;
    for (int i = 0; i < n - 1; i++) {
        int check_swaps = 0;
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                check_swaps = 1;
            }
        }
        if (!check_swaps)
            break;
            
        else {
            cout << "Buoc " << count << ": ";
                for (int k = 0; k < n; k++)
                    cout << arr[k] << " ";
            cout << endl;
            count++;
        }
    }
}

int main() {
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    
    bubbleSort(arr, n);

    return 0;
}