#include <bits/stdc++.h>
using namespace std;

string s;
// Ví dụ: num = "1234" 
// sumofdigit [0] = 1 = 1 
// sumofdigit [1] = 2 + 12 = 14 
// sumofdigit [2] = 3 + 23 + 123 = 149 
// sumofdigit [3] = 4 + 34 + 234 + 1234 = 1506 
// Kết quả = 1670

//phan tich
// sumofdigit [3] = 4 + 34 + 234 + 1234 
//            = 4 + 30 + 4 + 230 + 4 + 1230 + 4 
//            = 4 * 4 + 10 * (3 + 23 +123) 
//            = 4 * 4 + 10 * (sumofdigit [2])

// => cong thuc QHD
// sumofdigit [i] = (i + 1) * num [i] + 10 * sumofdigit [i-1]
// base case sumOfDigit[0]=s[0];
// vi bang phuong an 1 chieu nen chi can dung bien Temp luu cac sumOfdigit[i], va result luu kq
long long SUM(){
    long long temp=int(s[0]-'0');
    long long result=temp;
    for(int i=1;i<s.size();i++){
        temp=(i+1)*int(s[i]-'0')+10*temp;
        result+=temp;
    }
    return result;
}

main(){
    int t;cin>>t;
    while(t--){
            cin>>s;
            cout<<SUM()<<endl;

    }
}