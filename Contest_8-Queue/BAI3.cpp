#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, x;
    string str;
    deque <int> q;
    cin >> n;
    cin.ignore();
    while (n--) {
        cin >> str;

        if (str.compare("PUSHFRONT") == 0) {
            cin >> x;
            q.push_front(x);
        }

        else if (str.compare("PRINTFRONT") == 0) {
            if (q.empty())
                cout << "NONE\n";
            
            else 
                cout << q.front() << endl;
        }

        else if (str.compare("POPFRONT") == 0) {
            if (!q.empty())
                q.pop_front();
        }

        else if (str.compare("PUSHBACK") == 0) {
            cin >> x;
            q.push_back(x);
        }

        else if (str.compare("PRINTBACK") == 0) {
            if (q.empty())
                cout << "NONE\n";
            
            else 
                cout << q.back() << endl;
        }

        else if (str.compare("POPBACK") == 0) {
            if (!q.empty())
                q.pop_back();
        }
    }
    return 0;
}