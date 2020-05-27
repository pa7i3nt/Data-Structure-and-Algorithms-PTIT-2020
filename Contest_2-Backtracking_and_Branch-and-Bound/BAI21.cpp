#include <bits/stdc++.h>
using namespace std;

void permute(string str) {
    do {
        cout << str << " ";
    } while (next_permutation(str.begin(), str.end()));
    cout << endl;
}

int main() {
    int test_count;
    string str;
    cin >> test_count;
    while (test_count--) {
        cin >> str;
        permute(str);
    }
    return 0;
}