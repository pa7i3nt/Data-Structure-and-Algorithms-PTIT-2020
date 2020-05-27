#include <bits/stdc++.h>
using namespace std;

void findNumbers(vector<int>& arr, int sum,
                    vector<vector<int> >& res,
                    vector<int>& r, int i)
{
    if (sum < 0)
        return;

    if (sum == 0) {
        res.push_back(r);
        return;
    }

    while (i < arr.size() && sum - arr[i] >= 0) {
        r.push_back(arr[i]);

        findNumbers(arr, sum - arr[i], res, r, i);
        i++;

        r.pop_back();
    }
}

vector<vector<int> > combinationSum(vector<int>& arr, int sum) {
    sort(arr.begin(), arr.end());

    arr.erase(unique(arr.begin(), arr.end()), arr.end());

    vector<int> r;
    vector<vector<int> > res;
    findNumbers(arr, sum, res, r, 0);

    return res;
}

int main() {
    int test, n, sum;
    cin >> test;
    while (test--) {
        cin >> n >> sum;
        vector<int> arr (n);
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        vector<vector<int> > res = combinationSum(arr, sum);
        if (res.size() == 0)
            cout << "-1";
        else {
            for (int i = 0; i < res.size(); i++) {
                if (res[i].size() > 0) {
                    cout << "[";
                    for (int j = 0; j < res[i].size(); j++) {
                        if (j == res[i].size() - 1)
                            cout << res[i][j];
                        else 
                            cout << res[i][j] << " ";
                    }
                    cout << "] ";
                }
            }
        }
        cout << endl;
    }
    return 0;
}