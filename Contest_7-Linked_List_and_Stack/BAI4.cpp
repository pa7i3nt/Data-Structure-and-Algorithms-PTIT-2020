#include <bits/stdc++.h>
using namespace std;

bool result(string str) {
    stack <char> s;
    char ch;

    for (int i = 0; i < str.length(); i++) {
        if (str[i] == '(' || str[i] == '[' || str[i] == '{') {
            s.push(str[i]);
            continue;
        }

        if (s.empty())
            return false;

        switch (str[i])
        {
            case ')' : {
                ch = s.top();
                s.pop();
                if (ch == '[' || ch == '{')
                    return false;
                break;
            }
            
            case ']' : {
                ch = s.top();
                s.pop();
                if (ch == '(' || ch == '{')
                    return false;
                break;
            }

            case '}' : {
                ch = s.top();
                s.pop();
                if (ch == '(' || ch == '[')
                    return false;
                break;
            }
        }
    }
    
    return (s.empty());
}

int main() {
    int t;
    string str;
    cin >> t;
    while (t--) {
        cin >> str;
        if (result(str))
            cout << "YES" << endl;
        else 
            cout << "NO" << endl;
    }
    return 0;
}