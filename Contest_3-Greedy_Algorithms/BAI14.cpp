#include <bits/stdc++.h>
using namespace std;

string toString(long long n) {
    string s = "";
    while (n > 0) {
        s = char(n % 10 + '0') + s;
        n /= 10;
    }
    return s;
}

vector<string> perfectCubes(long long n) {
    vector<string> cubes;
    for (long long i = 1; i * i * i <= n; i++) {
        long long cube_at_i_th = i * i * i;

        string cubeString = toString(cube_at_i_th);
        cubes.push_back(cubeString);
    }
    return cubes;
}

string solution(long long n) {
    vector<string> str1 = perfectCubes(n);
    string str2 = toString(n);
    for (int i = str1.size() - 1; i >= 0; i--) {
        string currentCube = str1[i];
        int index = 0;
        for (int j = 0; j < str2.size(); j++) {
            if (str2[j] == currentCube[index])
                index++;
        }

        if (index == currentCube.size())
            return currentCube;
    }
    return "-1";
}

int main() {
    int test;
    long long n;
    cin >> test;
    while (test--) {
        cin >> n;
        cout << solution(n) << "\n";
    }
    return 0;
}