#include<bits/stdc++.h> 
using namespace std; 
string s1,s2;
// struct hangTu{
//     int heSo;
//     int soMu;
// };
// hangTu daThuc[10005];
int daThuc[10005];
int main() 
{ 
    int t; cin>>t;
    getline(cin,s1);
    while(t--){
        getline(cin,s1);
        getline(cin,s2);

        //tim bac lon nhat trong s1 s2
        int bacLonNhat;
        for(int i=0;i<s1.size();i++) 
            if(s1[i]=='^'){
                string temp="";
                for(int j=i+1;j<s1.size();j++){
                    if(s1[j]!=' ') temp+=s1[j];
                    else break;
                }
                bacLonNhat=stoi(temp);  
                break;
            }
        for(int i=0;i<s1.size();i++) 
            if(s1[i]=='^'){
                string temp="";
                for(int j=i+1;j<s1.size();j++){
                    if(s1[j]!=' ') temp+=s1[j];
                    else break;
                }
                bacLonNhat=max(stoi(temp),bacLonNhat);  
                break;
            }

        //reset daThuc sau moi case t
        for(int i=0;i<=bacLonNhat;i++) daThuc[i]=0;

        //update da thu cho cac s1
        for(int i=0;i<s1.size();i++){
           if(s1[i]=='x'){
               string num="";
               for(int j=i-2;j>=0;j--){
                   if(s1[j]>='1'&&s1[j]<='9'){
                       num=s1[j]+num;
                   }else break;
               }
               int HESO=stoi(num);
            //    cout<<HESO;
               string num2="";
               for(int j=i+2;j<s1.size();j++){
                   if(s1[j]>='0'&&s1[j]<='9'){
                       num2+=s1[j];
                   }else break;
               }
            //    cout<<num2;
               int SOMU=stoi(num2);
            //    cout<<SOMU;
                daThuc[SOMU]+=HESO;
           }
        }

        // update dathuc += voi s2.     copy paste phan tren thay s1->s2
        for(int i=0;i<s2.size();i++){
           if(s2[i]=='x'){
               string num="";
               for(int j=i-2;j>=0;j--){
                   if(s2[j]>='1'&&s2[j]<='9'){
                       num=s2[j]+num;
                   }else break;
               }
               int HESO=stoi(num);
            //    cout<<HESO;
               string num2="";
               for(int j=i+2;j<s2.size();j++){
                   if(s2[j]>='0'&&s2[j]<='9'){
                       num2+=s2[j];
                   }else break;
               }
            //    cout<<num2;
               int SOMU=stoi(num2);
            //    cout<<SOMU;
                daThuc[SOMU]+=HESO;
           }
        }

        //in da thuc ket qua thu duoc
        cout<<daThuc[bacLonNhat]<<"*x^"<<bacLonNhat;
        for(int i=bacLonNhat-1;i>=0;i--){
            if(daThuc[i]!=0) cout<<" + "<<daThuc[i]<<"*x^"<<i;
        }
        cout<<endl;
    }
    return 0; 
} 