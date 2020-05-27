#include <bits/stdc++.h>
using namespace std;

long long swapCount(string s) {
    // Keep track of '['
    vector<int> pos;
    for (int i = 0; i < s.length(); ++i)
        if (s[i] == '[')
            pos.push_back(i);

    int count = 0; // Dem so lan xuat hien '['
    int p = 0; // Track position of next '[' in pos
    long long sum = 0; // Luu tru ket qua

    for (int i = 0; i < s.length(); ++i) {
        // Tang count va di chuyen p toi vi tri tiep theo
        if (s[i] == '[') {
            ++count;
            ++p;
        }
        else if (s[i] == ']')
            --count;

        if (count < 0) {
            // Increment sum by number of swaps required
            // Cu the la position of next '[' - current position
            sum += pos[p] - i;
            swap(s[i], s[pos[p]]);
            ++p;

            count = 1;
        }
    }
    return sum;
}

int main() {
    int test;
    string s;
    cin >> test;
    while (test--) {
        cin >> s;
        cout << swapCount(s) << "\n";
    }
    return 0;
}