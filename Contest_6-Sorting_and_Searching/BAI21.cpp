#include <bits/stdc++.h>
using namespace std;

bool soSanh(pair<int, int> &p1, pair<int, int> &p2) {
    if (p1.second == p2.second)
        return p1.first < p2.first;
    
    return p1.second > p2.second;
}

void result(int arr[], int n) {
    map<int, int> mp;

    for (int i = 0; i < n; i++)
        mp[arr[i]]++;

    int size = mp.size();

    pair<int, int> p[size];

    int i = 0;
    for (auto it = mp.begin(); it != mp.end(); ++it)
        p[i++] = make_pair(it -> first, it -> second);

    sort(p, p + size, soSanh);

    for (int i = 0; i < size; i++) {
    int freq = p[i].second;
    while (freq--)
        cout << p[i].first << " ";
    }
    cout << endl;
}

int main() {
    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        
        result(arr, n);
    }
    return 0;
}