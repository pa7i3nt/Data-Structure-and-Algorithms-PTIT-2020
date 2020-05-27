#include <bits/stdc++.h>
using namespace std;

int row, col;
int mat[505][505], tab[505][505];

int res() {
    for (int i = 1; i <= col; i++)
        tab[1][i] = mat[1][i];
    
    for (int i = 1; i <= row; i++)
        tab[i][1] = mat[i][1];

    int res = INT_MIN;

    for (int i = 2; i <= row; i++) {
        for (int j = 2; j <= col; j++) {
            if (mat[i][j] == 1) {
                tab[i][j] = min(
                            min(tab[i - 1][j], tab[i][j - 1]),
                                tab[i - 1][j - 1]) + 1;
            }
            else 
                tab[i][j] = 0;

            res = max(res, tab[i][j]);
        }
    }

    return res;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        cin >> row >> col;
        for (int i = 1; i <= row; i++)
            for (int j = 1; j <= col; j++)
                cin >> mat[i][j];

        cout << res() << endl;
    }
    return 0;
}