#include <bits/stdc++.h>
using namespace std;

const int MAX_CHAR = 26;

long long result(string str, long long k) {
    transform(str.begin(), str.end(), str.begin(), ::tolower);
    long long len = str.length();

    // Neu k >= len, tra ve 0
    if (k >= len)
        return 0;

    // Mang chua so lan xuat hien
    // cua tung phan tu trong string
    long long freq[MAX_CHAR] = {0};

    // Tim so lan xuat hien cua tung phan tu
    for (long long i = 0; i < len; i++)
        freq[str[i] - 'a']++;

    // Push so lan xuat hien cua tung phan tu
    // vao priority_queue
    priority_queue <long long> q;
    for (long long i = 0; i < MAX_CHAR; i++)
        q.push(freq[i]);

    // Xoa k phan tu
    while (k--) {
        // Xoa phan tu top cua priority_queue
        // Giam so lan xuat hien cua phan tu top xuong 1
        // Tiep tuc day gia tri sau khi tru vao priority_queue
        long long tmp = q.top();
        q.pop();
        tmp--;
        q.push(tmp);
    }

    // Tim tong binh phuong
    long long res = 0;
    while (!q.empty()) {
        long long tmp = q.top();
        res += tmp * tmp;
        q.pop();
    }

    return res;
}

int main() {
    int t;
    long long k;
    string str;
    cin >> t;
    while (t--) {
        cin >> k;
        cin >> str;
        cout << result(str, k) << endl;
    }
    return 0;
}