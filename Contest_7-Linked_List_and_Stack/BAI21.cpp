#include <bits/stdc++.h>
using namespace std;

void next_greater(int n, int arr[], int NEXT_GREATER[]) {
    stack <int> st;

    for (int i = n - 1; i >= 0; i--) {
        while (!st.empty() && arr[st.top()] <= arr[i]) {
            st.pop();
        }

        if (st.empty())
            NEXT_GREATER[i] = -1;
        
        else 
            NEXT_GREATER[i] = st.top();
        
        st.push(i);
    }
}

void right_smaller(int n, int arr[], int RIGHT_SMALLER[]) {
    stack <int> st;

    for (int i = n - 1; i >= 0; i--) {
        while (!st.empty() && arr[st.top()] >= arr[i]) {
            st.pop();
        }

        if (st.empty())
            RIGHT_SMALLER[i] = -1;
        
        else 
            RIGHT_SMALLER[i] = st.top();
        
        st.push(i);
    }
}

void result(int n, int arr[]) {
    int NEXT_GREATER[n], RIGHT_SMALLER[n];

    next_greater(n, arr, NEXT_GREATER);
    right_smaller(n, arr, RIGHT_SMALLER);

    for (int i = 0; i < n; i++) {
        if (NEXT_GREATER[i] != -1 && RIGHT_SMALLER[NEXT_GREATER[i]] != -1)
            cout << arr[RIGHT_SMALLER[NEXT_GREATER[i]]] << " ";
        
        else 
            cout << -1 << " ";
    }

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