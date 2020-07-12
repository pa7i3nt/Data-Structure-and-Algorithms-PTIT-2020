#include <bits/stdc++.h>
using namespace std;

main() {
	int t,n,i,j,ans;
	cin>>t;
	while(t--){
	    cin>>n; ans = n;
	    int A[n];
	    for(i=0;i<n;i++) cin>>A[i];
	    stack<int>s;
	    for(i=0,j=1;j<n;i++,j++){
	        bool found=false;
	        if(A[i]>A[j])
	        s.push(A[i]);
	        else{
	        while(!s.empty()){
	            if(A[j]>s.top()){
                    s.pop();
                    found=true;
	            }
	            else break;
	        }
	        if(found) ans--;
	        }
	    }
	    ans--;
	    cout << ans << endl;
	}
}
