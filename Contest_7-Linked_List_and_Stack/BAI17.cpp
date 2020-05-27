#include <bits/stdc++.h>
using namespace std;

long long tinh(long long a, long long b, char c) {
    switch (c) {
        case '+' : return a + b;
        case '-' : return a - b;
        case '*' : return a * b;
        case '/' : return a / b;
    }
}

int tinh_tiento(string str) {
    stack<int> st;
    for (int i = str.length() - 1; i >= 0; i--) {
        if (isdigit(str[i]))
            st.push(str[i] - '0');
        
        else {
            int x1 = st.top(); st.pop();
            int x2 = st.top(); st.pop();
            int tmp = tinh(x1, x2, str[i]);
            st.push(tmp);
        }
    }
    return st.top();
}

int main() {
    int t;
    string str;
    cin >> t;
    cin.ignore();
    while (t--) {
        cin >> str;
        cout << tinh_tiento(str) << endl;
    }
    return 0;
}