#include<bits/stdc++.h>

using namespace std;

int binarySearch(int arr[], int l, int r, int x) 
{ 
    if (r >= l) { 
        int mid = l + (r - l) / 2;  
        if (arr[mid] <= x && arr[mid+1] > x) 
            return mid;  
        if (arr[mid] > x) 
            return binarySearch(arr, l, mid-1, x);  
        return binarySearch(arr, mid+1 , r, x); 
    } 
    //return r; 
} 

int main()
{
	int t=1;
	cin>>t;
	int n,k;
	while(t--)
	{
		cin>>n>>k;
		int a[n+1];
		for(int i=0;i<n;i++) cin>>a[i];
		
		long long ans=0;
		sort(a, a + n); 
  
	    for (int i = 0; i < n-1; i++) 
		{  
		//	cout<<binarySearch(a,i+1,n-1,k+a[i]-1);
	        ans = ans + binarySearch(a,i+1,n-1,k+a[i]-1) - i;
	    } 
	    cout<<ans<<endl;
	}

	return 0;
}
