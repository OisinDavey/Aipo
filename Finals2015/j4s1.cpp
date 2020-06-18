//
// Solved J4S1 - Bits equalizer, ngl I found this more difficult than S2 and S3, this is too guessy imo but it works
//

#include                <bits/stdc++.h>
#define MX_N            5001
#define mp              make_pair
#define mod7            1000000007
#define modpi           314159
#define PI              3.141592653589793238
#define pb              push_back
#define FastIO          ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define All(a)          a.begin(),a.end()
#define fi              first
#define se              second
#define ll              long long int
#define ull             unsigned long long int

int kx[8]  =            {+2, +2, -2, -2, +1, +1, -1, -1};
int ky[8]  =            {+1, -1, +1, -1, +2, -2, +2, -2};
int d9x[9] =            {+1, +1, +1, +0, +0, +0, -1, -1, -1};
int d9y[9] =            {+1, +0, -1, +1, +0, -1, +1, +0, -1};
int dx4[4] =            {+0, +0, +1, -1};
int dy4[4] =            {+1, -1, +0, +0};

ll gcd(ull a, ull b){
    return (a==0)?b:gcd(b%a,a);
}

ll lcm(ull a, ull b){
    return a*(b/gcd(a,b));
}

const long long INF = 1e18;

using namespace std;

int main(){
    int T;
    cin >> T;
    for(int I=1;I<=T;++I){
        int ans = 0;
        string a, b;
        cin >> a >> b;
        int n = a.size();
        int q = 0;
        int o = 0;
        int e = 0;
        int available = 0;
        for(int i=0;i<n;++i){
            if(a[i] == '?'){
                ++q;
            }else if(a[i] == '1' && b[i] == '0'){
                ++o;
            }else if(a[i] == '0' && b[i] == '1'){
                ++e;
            }
            if(b[i] == '1' && a[i] != '1'){
                ++available;
            }
        }
        if(o > available){
            cout << "Case " << I << ": " << -1 << endl;
        }else{
            cout << "Case " << I << ": " << q + o + max(0, (e - o)) << endl;
        }   
    }
}
