#include <bits/stdc++.h>
using namespace std;

const int MAX_CHAR = 26;

// Tra ve dau cua tung phan tu
// Vi du: a-b-(-c) thi ta co dau
// cua tung phan tu la: +a, -b, +c
bool sign(string s, int i) {
    if (i == 0)
        return true;

    if (s[i - 1] == '-')
        return false;

    return true;
}

// Dua phan tu co xuat hien trong phep tinh hay khong
// Neu co, them bien dem vao vector cua bang chu cai
// Neu khong, xoa bien dem ra khoi vector
void evaluate(string str, vector<int>& vec, bool add) {
    
    // stack chua sign
    stack<bool> stk;
    stk.push(true);

    int i = 0;
    while (str[i] != '\0') {
        if (str[i] == '+' || str[i] == '-') {
            i++;
            continue;
        }

        if (str[i] == '(') {
            if (sign(str, i))
                stk.push(stk.top());
            
            else 
                stk.push(!stk.top());
        }

        else if (str[i] == ')')
            stk.pop();

        else {
            if (stk.top())
                vec[str[i] - 'a'] += (sign(str, i) ? add ? 1 : -1 :
                                                 add ? -1 : 1);

            else 
                vec[str[i] - 'a'] += (sign(str, i) ? add ? -1 : 1 :
                                                 add ? 1 : -1);
        }

        i++;
    }
}

bool result(string str1, string str2) {
    vector<int> vec(MAX_CHAR, 0);

    evaluate(str1, vec, true);

    evaluate(str2, vec, false);

    for (int i = 0; i < MAX_CHAR; i++)
        if (vec[i] != 0)
            return false;

    return true;
}

int main() {
    int t;
    string str1, str2;
    cin >> t;
    cin.ignore();
    while (t--) {
        cin >> str1 >> str2;
        if (result(str1, str2))
            cout << "YES\n";
        
        else 
            cout << "NO\n";
    }
    return 0;
}