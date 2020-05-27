#include <iostream>
// #include <algorithm>
using namespace std;

int a[50],b[50],n,sum,testCase;



bool check(){
    int temp=0;
    for(int i=1;i<=n;i++){
        temp+=a[i]*b[i];
    } if(temp==sum/2) return 1; else return 0;
}

void backTrack(int i){
    if(testCase) return;
    for(int j=1;j>=0;j--){
            if(testCase) return;

        b[i]=j;
        if(i==n){
            if(check()) {testCase++;return;};
        }else backTrack(i+1);

    }
}
main(){
    int t; cin>>t;
    while(t--){
        testCase=0; sum=0;
        cin>>n; for(int i=1;i<=n;i++){cin>>a[i]; sum+=a[i];}
        // sort(a+1,a+n+1);
        if(n==1||(n==2&&a[1]!=a[2])||sum%2!=0);
        else backTrack(1);
        
        if(testCase) cout<<"YES"; else cout<<"NO";
        cout<<endl;
    }
}