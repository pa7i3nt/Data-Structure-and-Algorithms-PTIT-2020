#include <bits/stdc++.h>
using namespace std;

string result(string str) {
    stack <int> numbers;
    stack <char> ch;

    string tmp = "", res = "";

    for (int i = 0; i < str.length(); i++) {
        int count = 0;

        if (str[i] >= '0' && str[i] <= '9') {
            while (str[i] >= '0' && str[i] <= '9') {
                count = count * 10 + str[i] - '0';
                i++;
            }

            i--;
            numbers.push(count);
        }

        else if (str[i] == ']') {
            tmp = "";
            count = 0;

            if (!numbers.empty()) {
                count = numbers.top();
                numbers.pop();
            }

            while (!ch.empty() && ch.top() != '[') {
                tmp = ch.top() + tmp;
                ch.pop();
            }
            
            if (!ch.empty() && ch.top() == '[')
                ch.pop();

            for (int j = 0; j < count; j++)
                res = res + tmp;

            for (int j = 0; j < res.length(); j++)
                ch.push(res[j]);

            res = "";
        }

        else if (str[i] == '[') {
            if (str[i - 1] >= '0' && str[i - 1] <= '9')
                ch.push(str[i]);

            else {
                ch.push(str[i]);
                numbers.push(1);
            }
        }

        else 
            ch.push(str[i]);
    }

    while (!ch.empty()) {
        res = ch.top() + res;
        ch.pop();
    }

    // cout << res << endl;
    return res;
}

int main() {
    int t;
    string str;
    cin >> t;
    // cin.ignore();
    while (t--) {
        cin >> str;
        // result(str);
        cout << result(str) << endl;
    }
    return 0;
}