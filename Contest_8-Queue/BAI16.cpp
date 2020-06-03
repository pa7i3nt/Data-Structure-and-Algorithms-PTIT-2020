#include <bits/stdc++.h>
using namespace std;

typedef map<string, bool> msb;
typedef pair<string, int> psi;

string r_left(string s) {
    swap(s[0], s[3]);
    swap(s[1], s[3]);
    swap(s[3], s[4]);
    return s;
}

string r_right(string s) {
    swap(s[1], s[2]);
    swap(s[1], s[5]);
    swap(s[4], s[1]);
    return s;
}

string batDau = "";
string ketThuc = "";
msb mp;

int main() {
    int tmp;
    for (int i = 0; i < 6; i++) {
        cin >> tmp;
        batDau += (char)(tmp + '0');
    }

    for (int j = 0; j < 6; j++) {
        cin >> tmp;
        ketThuc += (char)(tmp + '0');
    }

    mp[batDau] = true;
    queue <psi> q;
    q.push(psi(batDau, 0));

    while (q.size()) {
        psi top = q.front();
        q.pop();
        if (top.first == ketThuc)
            return cout << top.second, 0;
        
        string sl = r_left(top.first);

        if (mp[sl] == false) {
            mp[sl] = true;
            q.push(psi(sl, top.second + 1));
        }

        string sr = r_right(top.first);
        if (mp[sr] == false) {
            mp[sr] = true;
            q.push(psi(sr, top.second + 1));
        }
    }
    return 0;
}