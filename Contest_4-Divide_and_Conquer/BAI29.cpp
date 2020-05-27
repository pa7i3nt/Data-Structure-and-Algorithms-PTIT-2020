#include <bits/stdc++.h>
using namespace std;

#define MAX 100000
double res;

struct Point {
    double x, y;
};

Point p[MAX];

bool compare_X_point(const Point& p1, const Point& p2) {
    return p1.x < p2.x;
}

bool compare_Y_point(const Point& p1, const Point& p2) {
    return p1.y < p2.y;
}

void distance(const Point& p1, const Point& p2) {
    double dist = sqrt( (p1.x - p2.x) * (p1.x - p2.x) +
                    (p1.y - p2.y) * (p1.y - p2.y) );

    if (dist < res)
        res = dist;
}

void searching(int left, int right) {
    if (right <= left)
        return;
    
    if (right == left + 1) { // Array [left, right] has only 2 elements
        distance(p[left], p[right]);

        // Arrange elements by y
        if (!compare_Y_point(p[left], p[right]))
            swap(p[left], p[right]);
        return;
    }

    int mid = (left + right) / 2;
    double mid_at_x = p[mid].x;

    searching(left, mid);
    searching(mid + 1, right);

    static Point temp[MAX];

    // Merge p[left, mid] and p[mid + 1, right], stored at array temp
    merge(p + left, p + mid + 1, p + mid + 1,
            p + right + 1, temp, compare_Y_point);

    // Copy from temp to p
    copy(temp, temp + right - left + 1, p + left);

    // Array temp satisfying |x_i - mid_at_x| < res
    // with number of elements is count
    // Because we sorted temp by compare_Y_point, so we have y increasing
    int count = 0;
    for (int i = left; i <= right; i++) {
        if (abs(p[i].x - mid_at_x) < res) {
            for (int j = count - 1; j >= 0 && temp[j].y > p[i].y - res; j--)
                distance(p[i], temp[j]);
            temp[count++] = p[i];
        }
    }
}

int main() {
    int test, n;
    cin >> test;
    while (test--) {
        cin >> n;
        for (int i = 0; i < n; i++)
            cin >> p[i].x >> p[i].y;
        
        res = 1E20;
        sort(p, p + n, compare_X_point);
        searching(0, n - 1);

        cout << fixed << setprecision(6) << res << endl;
    }
    return 0;
}