#include <bits/stdc++.h>
using namespace std;

int isPossible(string str) {
    // Mang chua so lan xuat hien cua moi phan tu
    unordered_map<char, int> freq;

    // Ghi nhan so lan xuat hien lon nhat
    int max_freq = 0;

    for (int j = 0; j < (str.length()); j++) {
        freq[str[j]]++;
        if (freq[str[j]] > max_freq)
            max_freq = freq[str[j]];
    }

    if (max_freq <= (str.length() - max_freq + 1))
        return true;
    return false;
}

int main() {
    int test;
    string str;
    cin >> test;
    while (test--) {
        cin >> str;
        if (isPossible(str))
            cout << "1";
        else 
            cout << "-1";
        cout << endl;
    }
    return 0;
}