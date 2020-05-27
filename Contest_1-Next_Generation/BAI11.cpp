#include <bits/stdc++.h>
using namespace std;

char flip(char c) {
    return (c == '0') ? '1' : '0';
}

string graytoBinary(string gray) {
    string binary = "";

    binary += gray[0];

    for (int i = 1; i < gray.length(); i++) {
        if (gray[i] == '0')
            binary += binary[i - 1];

        else 
            binary += flip(binary[i - 1]);

    }

    return binary;
}


int main() {
    int test_count;
    string str;
    cin >> test_count;
    while (test_count--) {
        cin >> str;
        cout << graytoBinary(str) << endl;
    }
    return 0;
}