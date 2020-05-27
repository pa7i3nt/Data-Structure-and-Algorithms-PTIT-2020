#include <bits/stdc++.h>
using namespace std;

long long search(long long arr1[], long long arr2[], int n) {
    int res = n;

    int left = 0, right = n - 1;
    while (left <= right) {

        int mid = (left + right) / 2;
        
        // Neu 2 phan tu o vi tri mid cua 2 day giong nhau
        // thi co nghia la phan tu can tim o phia sau vi tri mid
        // vi vay, cap nhat left = mid + 1
        if (arr2[mid] == arr1[mid])
            left = mid + 1;
        
        // Neu phan tu o vi tri mid cua 2 day khac nhau
        // thi co nghia la phan tu can tim o vi tri khac,
        // hoac la mid, hoac la o dang truoc vi tri mid
        // vi vay, cap nhat right = mid - 1
        else {
            res = mid;
            right = mid - 1;
        }
    }
    // khi ma vi tri righ lon hon left
    // thi tim thay ket qua
    return res;
}

int main() {
    int test, n;
    cin >> test;
    while (test--) {
        cin >> n;
        long long arr1[n], arr2[n-1];

        for (int i = 0; i < n; i++)
            cin >> arr1[i];
        
        for (int i = 0; i < n-1; i++)
            cin >> arr2[i];

        cout << search(arr1, arr2, n) + 1 << endl;
    }
    return 0;
}