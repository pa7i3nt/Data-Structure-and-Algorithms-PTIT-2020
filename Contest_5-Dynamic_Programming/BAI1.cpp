#include <bits/stdc++.h>
using namespace std;

int mat[1005][1005];

int tinh(string s1, string s2) {
    int m = s1.length();
    int n = s2.length();
    int i, j;
    for (i = 1; i <= m; i++) {
        for (j = 1; j <= n; j++) {
            if (s1[i-1] == s2[j-1])
                mat[i][j] = mat[i-1][j-1] + 1;
            else
                mat[i][j] = max(mat[i-1][j], mat[i][j-1]);
        }
    }
    
    return mat[m][n];
}

int main() {
    int test;
    string s1, s2;
    cin >> test;
    while (test--) {
        cin >> s1 >> s2;
        cout << tinh(s1, s2) << endl;
    }
    return 0;
}