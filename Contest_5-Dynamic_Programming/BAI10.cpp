#include <bits/stdc++.h>
using namespace std;

int arr[1005][1005], f[1005][1005];

int res(int row, int col) {
    int count = 1;
    while (count <= row && count <= col) {
        for (int i = count; i <= col; i++)
            f[count][i] = arr[count][i] +
                        min(min(f[count - 1][i], f[count][i - 1]),
                            f[count - 1][i - 1]);

        for (int j = count + 1; j <= row; j++)
            f[j][count] = arr[j][count] +
                        min(min(f[j - 1][count], f[j][count - 1]),
                            f[j - 1][count - 1]);

        count++;
    }

    return f[row][col];
}

int main() {
    f[0][0] = 0;
    for (int i = 1; i <= 1000; i++) {
        f[0][i] = INT_MAX;
        f[i][0] = INT_MAX;
    }

    int t, row, col;
    cin >> t;
    while (t--) {
        cin >> row >> col;
        for (int i = 1; i <= row; i++)
            for (int j = 1; j <= col; j++)
                cin >> arr[i][j];

        cout << res(row, col) << endl;
    }
    return 0;
}