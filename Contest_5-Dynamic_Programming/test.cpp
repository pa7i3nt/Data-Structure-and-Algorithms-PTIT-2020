

#include <bits/stdc++.h>
using namespace std;

int f[101][101];

// f[i][j] la day con chung dai nhat khac nhau cua 2 day s[0]->s[i] va s[0]->s[j]
// base case la f[0][j] va f[i][0] bang 0;
// res la f[lenS][lenS]

int countt(string s){
     for(int i=1;i<=s.size();i++){
         for(int j=1;j<=s.size();j++){
             if(i!=j&&s[i-1]==s[j-1]){
                 f[i][j]=f[i-1][j-1]+1;
             }else f[i][j]=max(f[i-1][j],f[i][j-1]);
         }
     }
     return f[s.size()][s.size()];
}

main(){

    int t;cin>>t;
    while(t--){
        string s; cin>>s>>s;
        cout<<countt(s)<<endl;
    }
}