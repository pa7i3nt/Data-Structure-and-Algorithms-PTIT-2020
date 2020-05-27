#include <bits/stdc++.h>
using namespace std;

int result(string str) {
    stack <char> s;

    for (char ch : str) {
        if (ch == ')' && !s.empty()) {
            if (s.top() == '(')
                s.pop();
            else 
                s.push(ch);
        }

        else 
            s.push(ch);
    }

    int stack_len = s.size();
    int n = 0;

    while (!s.empty() && s.top() == '(') {
        s.pop();
        n++;
    }

    return (stack_len / 2 + n % 2);
}

int main() {
    int t;
    string str;
    cin >> t;
    cin.ignore();
    while (t--) {
        cin >> str;
        cout << result(str) << endl;
    }
    return 0;
}