#include <bits/stdc++.h>
using namespace std;

vector<int> my_vec;
vector<int> prime;
vector<vector<int> > res;

bool isPrime(int x) {
    // square root of x
    int sqroot = sqrt(x);
    bool flag = true;

    // since 1 is not prime number
    if (x == 1)
        return false;

    // if any factor is found return false
    for (int i = 2; i <= sqroot; i++)
        if (x % i == 0)
            return false;

    return true;
}

void display() {
    int length = my_vec.size();
    vector<int> tmp_res;
    for (int i = 0; i < length; i++) {
        tmp_res.push_back(my_vec[i]);
    }
    res.push_back(tmp_res);
}

void primeSum(int total, int N, int S, int index) {
    // vector<vector<int> > res;
    // if total equals S And
    // total is reached using N primes
    if (total == S && my_vec.size() == N) {
        display();
        return;
    }

    // if total is greater than S
    // or if index has reached last element
    if (total > S || index == prime.size())
        return;

    // add prime[index] to my_vec vector
    my_vec.push_back(prime[index]);

    // include the (index)th prime to total
    primeSum(total + prime[index], N, S, index + 1);

    // remove element from my_vec vector
    my_vec.pop_back();

    // exclude (index)th prime
    primeSum(total, N, S, index + 1);
}

void allPrime(int N, int S, int P) {
    // all primes less than S itself
    for (int i = P; i <= S; i++) {
        // if i is prime add it to prime vector
        if (isPrime(i))
            prime.push_back(i);
    }

    // if primes are less than N
    if (prime.size() < N)
        return;
    primeSum(0, N, S, 0);
}

int main() {
    int test, N, P, S;
    cin >> test;
    while (test--) {
        my_vec.clear();
        res.clear();
        prime.clear();
        cin >> N >> P >> S;
        allPrime(N, S, P);
        cout << res.size() << endl;
        for (int i = 0; i < res.size(); i++) {
            for (int j = 0; j < res[i].size(); j++) {
                cout << res[i][j] << " ";
            }
            cout << "\n";
        }
    }
    return 0;
}

