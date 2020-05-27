#include <bits/stdc++.h>
using namespace std;

int mat[100][100], n;
char ch[100];
bool printed = false;
bool visited[100][100];
// k: buoc di

void in(int k) {
    for (int i = 0; i < k; i++)
        cout << ch[i];
    cout << " ";
    printed = true;
}

void dequy(int i, int j, int k) {
    // if (mat[1][1] == 0 || mat[n][n] == 0)
    //     return;
    if (i == n - 1 && j == n - 1) {
        in(k);
        return;
    }

    if (i != n && mat[i+1][j] == 1 && !visited[i+1][j]) {
        visited[i][j] = true;
        ch[k] = 'D';
        dequy(i+1, j, k+1);
        visited[i][j] = false;
    }

    if (j != 1 && mat[i][j-1] == 1 && !visited[i][j-1]) {
        visited[i][j] = true;
        ch[k] = 'L';
        dequy(i, j-1, k+1);
        visited[i][j] = false;
    }

    if (j != n && mat[i][j+1] == 1 && !visited[i][j+1]) {
        visited[i][j] = true;
        ch[k] = 'R';
        dequy(i, j+1, k+1);
        visited[i][j] = false;
    }

    if (i != 1 && mat[i-1][j] == 1 && !visited[i-1][j]) {
        visited[i][j] = true;
        ch[k] = 'U';
        dequy(i-1, j, k+1);
        visited[i][j] = false;
    }
}

int main() {
    int test_count;
    cin >> test_count;
    while (test_count--) {
        cin >> n;

        for (int i = 0; i < 100; i++) {
            for (int j = 0; j < 100; j++) {
                mat[i][j] = 0;
                visited[i][j] = false;
            }
        }
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> mat[i][j];
            }
        }

        printed = false;

        if (mat[0][0] != 1)
            cout << "-1";
        else {
            dequy(0, 0, 0);
            if (!printed)
                cout << "-1";
        }

        cout << endl;
    }
    return 0;
}