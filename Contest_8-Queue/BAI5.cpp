#include <bits/stdc++.h>
using namespace std;

void convert(int n) {
    int binaryNum[32];
    int i = 0;

    while (n > 0) {
        binaryNum[i] = n % 2;
        n /= 2;
        i++;
    }

    for (int j = i - 1; j >= 0; j--)
        cout << binaryNum[j];
    
    cout << " ";
}

int main() {
    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 1; i <= n; i++)
            convert(i);
        
        cout << endl;
    }
    return 0;
}