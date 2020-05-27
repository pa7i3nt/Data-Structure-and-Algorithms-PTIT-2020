#include <bits/stdc++.h>
using namespace std;

bool result(string str) {
    int n = str.length();
    stack <char> s;

    for (char ch : str) {
        if (ch == ')') {
            char top = s.top();
            s.pop();

            int count = 0;

            while (top != '(') {
                count++;
                top = s.top();
                s.pop();
            }

            if (count <= 1)
                return true;
        }

        else s.push(ch);
    }

    return false;
}

int main() {
    int t;
    string str;
    cin >> t;
    cin.ignore();
    while (t--) {
        getline(cin, str);
        if (result(str))
            cout << "Yes\n";
        else 
            cout << "No\n";
    }
    return 0;
}