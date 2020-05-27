#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    string str;
    cin >> t;
    cin.ignore();
    while (t--) {
        cin >> str;
        int i = str.length() - 1;
        
        while (str[i] != '0' && i > 0) {
            str[i] = '0';
            i--;
        }
        if (str[i] == '1')
            str[i] = '0';
        else 
            str[i] = '1';

        for (int j = 0; j < str.length(); j++)
            cout << str[j];
        cout << endl;
    }
    return 0;
}