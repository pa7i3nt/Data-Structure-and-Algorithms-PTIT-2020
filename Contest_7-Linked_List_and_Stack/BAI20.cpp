#include <bits/stdc++.h>
using namespace std;

void result(int n, int arr[]) {
    stack <int> st;
    int res[n];

    for (int i = n - 1; i >= 0; i--) {
        while (!st.empty() && st.top() <= arr[i]) {
            st.pop();
        }

        if (st.empty())
            res[i] = -1;
        
        else 
            res[i] = st.top();
        
        st.push(arr[i]);
    }
    
    for (int i = 0; i < n; i++)
        cout << res[i] << " ";

    cout << endl;
}

int main() {
    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++)
            cin >> arr[i];

        result(n, arr);
    }
    return 0;
}