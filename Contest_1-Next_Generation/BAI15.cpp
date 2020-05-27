#include <bits/stdc++.h>
using namespace std;

int main() {
    int test_count, test_num;
    string str;
    cin >> test_count;
    while (test_count--) {
        cin >> test_num >> str;
        if (next_permutation(str.begin(), str.end()) == false)
            cout << test_num << " BIGGEST" << endl;
        else 
            cout << test_num << " " << str << endl;
    }
    return 0;
}