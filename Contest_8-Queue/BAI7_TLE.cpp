#include <bits/stdc++.h>
using namespace std;

void result(long long n) {
    long long count = 0;
    queue <string> q;
    q.push("1");

    while (true) {
        string s1 = q.front();
        q.pop();

        if (stoull(s1) > n)
            break;
        
        count++;

        string s2 = s1;

        q.push(s1.append("0"));
        q.push(s2.append("1"));
    }
    
    cout << count << endl;
}

int main() {
    long long t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        result(n);
    }
    return 0;
}