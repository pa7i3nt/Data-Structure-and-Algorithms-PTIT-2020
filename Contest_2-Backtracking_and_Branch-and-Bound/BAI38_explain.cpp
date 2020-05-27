#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
int z,y;
const ll    maximum = LONG_LONG_MAX;
ll          p[20] = {2,3,5,7,11,13,17,19,23,29};
ll          n, gaugau = maximum;

void nhailainhucho(int i, ll a, int b) {
	y=b;
	if (b > n)  return  ;
	if (b == n) gaugau = min(gaugau, a);
	for (int j=1;; j++) {
		if (a*p[i] > gaugau) break;
		a *= p[i];
		cout << "i = " << i <<" j= "<<j << " gaugau = " << gaugau <<" a =  " << a << " b = "<< b << endl;
		if (a < 0) break;
		
		nhailainhucho(i+1, a,b*(j+1));
	}
	
}


int main() {
    cout <<"Gau gau ang ang nhap gia tri de : " ;
	cin >> n;
	nhailainhucho(0,1,1);
	cout << gaugau;

	return 0;
}