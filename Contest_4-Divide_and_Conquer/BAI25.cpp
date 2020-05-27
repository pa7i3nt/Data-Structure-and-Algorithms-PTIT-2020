#include <bits/stdc++.h>
using namespace std;

long long F[100];

char Fibo(int n, long long k) {
	if (n == 1)
		return 'A';

	if (n == 2)
		return 'B';

	if (k <= F[n-2])
		return Fibo(n-2, k);

	return Fibo(n-1, k - F[n-2]);
}

int main() {
	F[1] = 1;
	F[2] = 1;
	for (int i = 3; i < 93; i++)
		F[i] = F[i-1] + F[i-2];
	int test, n;
	long long k;
	cin >> test;
	while (test--) {
		cin >> n >> k;
		cout << Fibo(n, k) << endl;
	}
	return 0;
}