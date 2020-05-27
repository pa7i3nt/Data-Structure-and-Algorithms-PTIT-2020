#include <bits/stdc++.h>
using namespace std;

bool compareString(string s1, string s2) {
    return (s1.compare(s2));
}

void helper(string s, int index, int left, int right, int pair,
            string path, vector < string > & res)
    // pair: the num of "(" which is marked to be pair
    // and need find a ')'
{
    if (index >= s.size())
    {
        if (0 == left && 0 == right && 0 == pair)
            res.push_back(path);
        return;
    }

    if ('(' != s[index] && ')' != s[index])
    {
        helper(s, index + 1, left, right, pair,
                        path + s[index], res);
    }

    else {
        if ('(' == s[index]) {
            // s[index] is marked as extra '('
            if (left > 0)
                helper(s, index + 1, left - 1, right,
                                pair, path, res);

            helper(s, index + 1, left, right, pair + 1,
                        path + s[index], res);
            // s[index] is marked as matched '(' and
            // is added to the path
        }

        if (')' == s[index]) {
            // s[index] is marked as extra ')'
            if (right > 0)
                helper(s, index + 1, left, right - 1,
                                pair, path, res);

            if (pair > 0)
                helper(s, index + 1, left, right, pair - 1,
                            path + s[index], res);
            // s[index] is marked as matched ')'
            // so the pair decrease 1
        }
    }
}

void removeInvalidParentheses(string s)
{
    vector < string > res;
    int left = 0, right = 0;
    // left: extra num of '('
    // right: extra num of ')'

    for (char c : s) {
        // looping through every character of string s
        if (c == '(')
            left++;
        else if (c == ')')
            left > 0 ? left-- : right++;
    }
    
    res.clear();
    helper(s, 0, left, right, 0, "", res);

    if (res.front() == "")
        cout << "-1";
    else {
        sort(res.begin(), res.end(), compareString);
        for (int i = 0; i < res.size(); i++)
            cout << res.at(i) << " ";
    }

    cout << endl;
}


int main() {
    // string s1 = "(u)()()";
    // string s2 = "(u())()";
    // bool check = compareString(s1, s2);
    // cout << check << endl;
    int test;
    string s;
    cin >> test;
    while (test--) {
        cin >> s;
        removeInvalidParentheses(s);
    }
    return 0;
}