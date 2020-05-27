#include <bits/stdc++.h>
using namespace std;

int a, b, c, d, e, res;
int arr[6], mark[6], permutationArray[6];

int operators[4];
// array stored +, -, *

bool testExpression() {
    int tmp;
    switch (operators[1]) {
        case 1: {
            tmp = permutationArray[1] + permutationArray[2];
            break;
        }

        case 2: {
            tmp = permutationArray[1] - permutationArray[2];
            break;
        }

        case 3: {
            tmp = permutationArray[1] * permutationArray[2];
            break;
        }
    }

    for (int i = 2; i <= 4; i++) {
        switch (operators[i]) {
            case 1: {
                tmp += permutationArray[i+1];
                break;
            }

            case 2: {
                tmp -= permutationArray[i+1];
                break;
            }

            case 3: {
                tmp *= permutationArray[i+1];
                break;
            }
        }
    }
    return tmp == 23;
}

void makeExpression(int i) {
    if (res)
        return;
    
    for (int j = 1; j <= 3; j++) {
        operators[i] = j;
        if (i == 4) {
            if (testExpression()) {
                res++;
                if (res)
                    return;
            }
        }
        else makeExpression(i+1);
    }
}

void makePermutation() {
    for (int i = 1; i <= 5; i++) {
        switch (arr[i]) {
            case 1: {
                permutationArray[i] = a;
                break;
            }
            
            case 2: {
                permutationArray[i] = b;
                break;
            }

            case 3: {
                permutationArray[i] = c;
                break;
            }

            case 4: {
                permutationArray[i] = d;
                break;
            }

            case 5: {
                permutationArray[i] = e;
                break;
            }
        }
    }
}

void permu(int i) {
    if (res)
        return;
    
    for (int j = 1; j <= 5; j++) {
        if (res)
            return;
        if (!mark[j]) {
            arr[i] = j;
            mark[j] = 1;
            if (i == 5) {
                makePermutation();
                makeExpression(1);
            }
            else permu(i+1);
            mark[j] = 0;
        }
    }
}

int main() {
    int test;
    cin >> test;
    while (test--) {
        res = 0;
        cin >> a >> b >> c >> d >> e;
        permu(1);

        if (res)
            cout << "YES";
        else 
            cout << "NO";

        cout << "\n";
    }
    return 0;
}