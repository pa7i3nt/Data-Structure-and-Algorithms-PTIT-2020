#include <bits/stdc++.h>
using namespace std;

#define MAX 505

int burnDownStack(std::stack<int>& lefts, int A[], int i, int h) {
    int max = 0;
    while (!lefts.empty() && A[lefts.top()] > h) {
        int left = A[lefts.top()];
        lefts.pop();
        int len = lefts.empty() ? i : i - (lefts.top() + 1);

        max = std::max(max, len*left);
    } 
    return max;
}

int maxHist(int n, int h[]) {
    std::stack<int> lefts;
    int res = 0;
    for (int i = 0; i < n; i++) {
        res = std::max(res, burnDownStack(lefts, h, i, h[i]));
        lefts.push(i);
    }
    return std::max(res, burnDownStack(lefts, h, n, -1));
}

int maxArea(int M[MAX][MAX], int n, int m) {
    int hist[m] = {0};
    
    int res = 0;
    for (int row = 0; row < n; row++) {
        for (int col = 0; col < m; col++) {
            if (M[row][col] == 0) {
                hist[col] = 0;
            } else {
                hist[col]++;
            }
        }
        res = std::max(res, maxHist(m, hist));
    }
    
    return res;
}

int main() {
    int t, n, m;
    int mat[MAX][MAX];
    cin >> t;
    while (t--) {
        cin >> n >> m;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> mat[i][j];
            }
        }

        cout << maxArea(mat, n, m) << endl;
    }
    return 0;
}