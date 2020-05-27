// #include <bits/stdc++.h>
// using namespace std;
// long long n,l,r;

// string something(long long n){
//     if(n==1) return "1";
//     string temp=something(n/2);
//     return temp + char((n%2)+'0')+ temp;

// }

// main(){
//     int t; cin>>t;
//     while(t--){
//         cin>>n>>l>>r;
//         string test=something(n); 
//         long long count=0;
//         for(int i=l;i<=r;i++)
//             if(test[i]=='1') count++;
//         cout<<count<<endl;
//     }    
// }
/*author : mdp*/
#include<bits/stdc++.h>
using namespace std;
#define ONLINE_JUDGE "ONLINE_JUDGE"
#define setIO() ios::sync_with_stdio(false); cin.tie(0);
#define all(a) a.begin(),a.end()
#define fill(x,b) memset((x),b,sizeof((x)))
#define fill2D(x,r,c,b) memset((x),b, sizeof(x[0][0]) * r * c)
typedef long long ll;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<string> vs;
typedef vector<ii> vpii;
int test = 1 , MULTI_TEST = 1; 
vector < ll > v;
vector < ll > pw;
ll n,l,r;
ll power(ll a, ll b) {
    if (b == 0) return 1;
    if (b == 1) return a;
    ll p = power(a, b >> 1);
    if (b & 1) return a * p * p;
    else return p * p;
}

void Input(){
     cin >> n >> l >> r;
     v.clear();
}   
void Solve(){
    while (n) {
        v.push_back(n);
        n >>= 1;
    }
    int k = v.size() - 1;
    int ans = 0;
    for (ll i = l ; i <= r; i++) {
        if (i & 1) ans++;
        else {
            ll val = i;
            //if (val > power(2, k)) val -= power(2, k);
            while (val & (val - 1)) {
                int x = upper_bound(pw.begin(), pw.end(), val) - pw.begin() - 1;
                val -= pw[x];
            }
            ans += v[k - (lower_bound(pw.begin(), pw.end(), val) - pw.begin())] & 1;
        }   
    }
    cout << ans << '\n';
}
int main(){
    setIO();
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    for (int i = 0 ; i < 50; i++) pw.push_back(power(2, i));
    
    if(MULTI_TEST == 1) cin >> test;
    for(int i = 1 ; i <= test ; i++){Input(); Solve();}
    return 0;
}