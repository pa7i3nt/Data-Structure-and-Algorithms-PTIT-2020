#include <bits/stdc++.h>
#define MAX 8

using namespace std;

bool isSafe(int row, int col, int mat[][MAX],
                int n, bool visited[][MAX])
{
    if (row == -1 || row == n || col == -1 ||
                col == n || visited[row][col]
                        || mat[row][col] == 0)
        return false;

    return true;
}

void printCondition(int row, int col, int mat[][MAX],
        int n, string& path, vector<string>&
        possiblePaths, bool visited[][MAX])
{
    if (row == -1 || row == n || col == -1
            || col == n || visited[row][col]
                        || mat[row][col] == 0)
        return;

    if (row == n - 1 && col == n - 1) {
        possiblePaths.push_back(path);
        return;
    }

    visited[row][col] = true;

    // Kiem tra co the di xuong duoi hay khong
    if (isSafe(row + 1, col, mat, n, visited)) {
        path.push_back('D');
        printCondition(row + 1, col, mat, n, path,
            possiblePaths, visited);
        path.pop_back();
    }

    // Kiem tra co the di sang trai hay khong
    if (isSafe(row, col - 1, mat, n, visited)) {
        path.push_back('L');
        printCondition(row, col - 1, mat, n, path,
            possiblePaths, visited);
        path.pop_back();
    }

    // Kiem tra co the di sang phai hay khong
    if (isSafe(row, col + 1, mat, n, visited)) {
        path.push_back('R');
        printCondition(row, col + 1, mat, n, path,
            possiblePaths, visited);
        path.pop_back();
    }

    // Kiem tra co the di len tren hay khong
    if (isSafe(row - 1, col, mat, n, visited)) {
        path.push_back('U');
        printCondition(row - 1, col, mat, n, path,
            possiblePaths, visited);
        path.pop_back();
    }

    visited[row][col] = false;
}

void printPath(int mat[MAX][MAX], int n) {
    vector<string> possiblePaths;
    string path;
    bool visited[n][MAX];
    memset(visited, false, sizeof(visited));

    printCondition(0, 0, mat, n, path,
                    possiblePaths, visited);

    if (possiblePaths.size() == 0)
        cout << "-1";
    else {
        for (int i = 0; i < possiblePaths.size(); i++)
        cout << possiblePaths[i] << " ";
    }
    cout << endl;
}

int main() {
    int test_count, n;
    cin >> test_count;
    while (test_count--) {
        cin >> n;
        int mat[MAX][MAX];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> mat[i][j];
            }
        }
        printPath(mat, n);
    }
    return 0;
}