#include <bits/stdc++.h>
using namespace std;

stack <long long> giatri;
stack <char> toantu;

long long tinh(long long a, long long b, char c) {
    switch (c) {
        case '+' : return a + b;
        case '-' : return a - b;
        case '*' : return a * b;
        case '/' : return a / b;
    }
}

int priority(char c) {
    if (c == '+' || c == '-')
        return 1;
    
    if (c == '*' || c == '/')
        return 2;
    
    return 0;
}

void capnhat() {
    long long x1 = giatri.top(); giatri.pop();
    long long x2 = giatri.top(); giatri.pop();
    char dau = toantu.top(); toantu.pop();
    giatri.push(tinh(x2, x1, dau));
}

long long tinh_trungto(string str) {
    int n = str.length(), i;

    for (i = 0; i < n; i++) {
        if (str[i] == '(')
            toantu.push(str[i]);
        
        else if (isdigit(str[i])) {
            long long x = 0;

            while (i < n && isdigit(str[i])) {
                x = (x * 10) + (str[i] - '0');
                i++;
            }

            if (!isdigit(str[i]))
                i--;
            
            giatri.push(x);
        }

        else if (str[i] == ')') {
            while (!toantu.empty() && toantu.top() != '(') {
                capnhat();
            }

            if (!toantu.empty())
                toantu.pop();
        }

        else {
            while (!toantu.empty() && priority(toantu.top()) >= priority(str[i])) {
                capnhat();
            }

            toantu.push(str[i]);
        }
    }
    
    while (!toantu.empty()) {
        capnhat();
    }

    return giatri.top();
}

int main() {
    int t;
    string str;
    cin >> t;
    cin.ignore();
    while (t--) {
        cin >> str;
        cout << tinh_trungto(str) << endl;
    }
    return 0;
}