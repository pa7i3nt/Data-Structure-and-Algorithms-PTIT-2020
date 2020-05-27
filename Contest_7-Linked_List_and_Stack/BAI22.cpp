#include <bits/stdc++.h>
using namespace std;

long long result(long long arr[], long long n) {
    stack <long long> st;

    long long res = 0;
    long long tp;
    long long area_with_top;

    long long i = 0;
    while (i < n) {
        if (st.empty() || arr[st.top()] <= arr[i])
            st.push(i++);

        else {
            tp = st.top();
            st.pop();

            area_with_top = arr[tp] * (st.empty() ? i :
                                i - st.top() - 1);

            if (res < area_with_top)
                res = area_with_top;
        }
    }

    while (!st.empty()) {
        tp = st.top();
        st.pop();

        area_with_top = arr[tp] * (st.empty() ? i :
                                i - st.top() - 1);

        if (res < area_with_top)
            res = area_with_top;
    }

    return res;
}

int main() {
    int t; 
    long long n;
    cin >> t;
    while (t--) {
        cin >> n;
        long long arr[n];
        for (long long i = 0; i < n; i++)
            cin >> arr[i];

        cout << result(arr, n) << endl;
    }
    return 0;
}