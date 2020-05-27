#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int M=1e9+7;
ll luyThua(int n, int k) {
	if(k==0) return 1;
	ll x=luyThua(n,k/2);
	if(k%2==0) return x*x%M;
	return n*(x*x%M)%M;
}
int main() {
	int t,n,k;
	cin >>t;
	while(t--) {
		cin >>n>>k;
		cout <<luyThua(n,k)<<endl;
	}
}
