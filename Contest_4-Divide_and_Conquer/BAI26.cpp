#include <bits/stdc++.h>
using namespace std;

string sumBase(int base, string a, string b) {
    int len_a = a.size();
    int len_b = b.size();

    string sum, str;
    str = "";
    sum = "";

    int diff;
    diff = abs(len_a - len_b);

    // Them o vao dang truoc cua so nho hon
    // de 2 so co do dai bang nhau
    for (int i = 1; i <= diff; i++)
        str += "0";

    // Kiem tra so nao co do dai nho hon
    // de them str vao trong chuoi
    // Muc dich la de 2 chuoi co do dai bang nhau
    if (len_a < len_b)
        a = str + a;
    else 
        b = str + b;

    int current, carry = 0;
    // carry: so nho
    // current: ket qua

    for (int i = max(len_a, len_b) - 1; i > -1; i--) {
        current = carry + (a[i] - '0') + (b[i] - '0');

        carry = current / base;

        current %= base;

        sum = (char)(current + '0') + sum;
    }

    if (carry > 0)
        sum = (char)(carry + '0') + sum;
    
    return sum;
}

int main() {
    string a, b, sum;
    int base;

    cin >> base;
    cin >> a >> b;

    sum = sumBase(base, a, b);
    cout << sum << "\n";

    return 0;
}