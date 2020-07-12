#include <bits/stdc++.h>
using namespace std;
main() {
	int t,N;
	cin>>t;
	while(t--){
	    cin>>N;
	    vector<int> a(N);
	    for(auto &x:a) cin>>x;
	    map<int,bool> m;
	    m[a[0]] = true;
	    int isBST = 1;
	    for(int i =1; i< N;i++){
	        if(a[i] < a[i-1]){
	            isBST = 0;
	            break;
	        }
	        if(m[a[i]] == true){
	            isBST = 0;
	            break;
	        }
	        m[a[i]] = true;
	    }
	    cout<<isBST<<endl;
	}
}
