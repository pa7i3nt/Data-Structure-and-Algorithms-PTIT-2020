#include <bits/stdc++.h>
using namespace std;

string str;
long long a[25], b[25], alo[25], close_brackets, open_brackets;
long long parentheses[25], character[205];
long long len;
string res[5125];
long long idx = 0;

void update() {
    for (long long i = 0; i < len; i++)
        character[i] = 1;
    
    for (long long i = 1; i <= close_brackets; i++) {
        if (parentheses[i] == 0) {
            character[a[i]] = 0;
            character[b[i]] = 0;
        }

    }

    idx++;
    res[idx] = "";

    for (long long i = 0; i < len; i++)
        if (character[i])
            res[idx] += str[i];
}

void Try(long long i) {
    for (long long j = 0; j <= 1; j++) {
        parentheses[i] = j;
        if (i == close_brackets)
            update();
        
        else 
            Try(i + 1);
    }
}

int main() {
    cin >> str;
    open_brackets = 0, close_brackets = 0;
    len = str.length();

    for (long long i = 0; i < len; i++) {
        if (str[i] == '(') {
            open_brackets++;
            alo[open_brackets] = i;
        }

        else if (str[i] == ')') {
            close_brackets++;
            a[close_brackets] = alo[open_brackets];
            b[close_brackets] = i;
            open_brackets--;
        }
    }

    Try(1);

    idx--;
    sort(res + 1, res + 1 + idx);
    res[0] = "*";

    for (long long i = 1; i <= idx; i++)
        if (res[i] != res[i - 1])
            cout << res[i] << endl;

    return 0;
}