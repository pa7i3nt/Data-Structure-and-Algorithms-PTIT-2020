#include <bits/stdc++.h>
using namespace std;

typedef vector<vector<long long>> Matrix;
const int M = 1e9 + 7;

long long n, k;

Matrix multiplyMatrix(Matrix mat1, Matrix mat2)
{
    Matrix temp;
    temp.resize(n);
    for (int i = 0; i < n; i++)
    {
        temp[i].resize(n);
        for (int j = 0; j < n; j++)
        {
            temp[i][j] = 0;
            for (int k = 0; k < n; k++)
            {
                temp[i][j] = (temp[i][j] % M + (mat1[i][k] % M) * (mat2[k][j] % M)) % M;
            }
        }
    }
    return temp;
}

Matrix matPow(Matrix originMat, long long k)
{
    if (k == 1)
        return originMat;
    Matrix tmp = matPow(originMat, k / 2);
    if (k % 2 == 0)
        return multiplyMatrix(tmp, tmp);
    else
        return multiplyMatrix(multiplyMatrix(tmp, tmp), originMat);
}

int main()
{
    int test;
    cin >> test;
    while (test--)
    {
        cin >> n >> k;
        Matrix originMat;
        originMat.resize(n);
        for (int i = 0; i < n; i++)
        {
            originMat[i].resize(n);
            for (int j = 0; j < n; j++)
            {
                cin >> originMat[i][j];
            }
        }

        Matrix res = matPow(originMat, k);
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cout << res[i][j] << " ";
            }
            cout << endl;
        }
    }
    return 0;
}