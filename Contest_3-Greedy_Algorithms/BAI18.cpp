#include <bits/stdc++.h>
using namespace std;

void solution(int sum) {
    int a = 0, b = 0;
    while (sum > 0) {
        if (sum % 7 == 0) {
            b++;
            sum -= 7;
        }
        else if (sum % 4 == 0) {
            a++;
            sum -= 4;
        }
        else {
            a++;
            sum -= 4;
        }
    }

    if (sum < 0) {
        cout << "-1\n";
        return;
    }

    for (int i = 0; i < a; i++)
        cout << 4;
    
    for (int i = 0; i < b; i++)
        cout << 7;
    
    cout << endl;
}

int main() {
    int test, n;
    cin >> test;
    while (test--) {
        cin >> n;
        solution(n);
    }
    return 0;
}

