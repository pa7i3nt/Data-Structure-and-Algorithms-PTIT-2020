#include <bits/stdc++.h>
using namespace std;

string num1, num2;

int min_sum() {
    for (int i = 0; i < num1.length(); i++)
        if (num1[i] == '6')
            num1[i] = '5';
    for (int i = 0; i < num2.length(); i++)
        if (num2[i] == '6')
            num2[i] = '5';
    return stoi(num1) + stoi(num2);
}

int max_sum() {
    for (int i = 0; i < num1.length(); i++)
        if (num1[i] == '5')
            num1[i] = '6';
    for (int i = 0; i < num2.length(); i++)
        if (num2[i] == '5')
            num2[i] = '6';
    return stoi(num1) + stoi(num2);
}

int main() {
    cin >> num1 >> num2;
    cout << min_sum() << " " << max_sum() << "\n";
    return 0;
}