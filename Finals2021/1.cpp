//
// ~oisín~ C++ Template
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

vector<ll> dec_to_base(ll inp, ll base){
    vector<ll> ans;
    while(inp > 0ll){
        ans.pb(inp%base);
        inp /= base;
    }
    return ans;
}

bool prime(ll x){
    if(x <= 1){
        return false;
    }
    ll S = sqrt(x);
    for(ll i=2ll;i<=S;++i){
        if(x%i == 0){
            return false;
        }
    }
    return true;
}

int main(){
    ll n;
    cin >> n;
    for(ll b=2;b<10;++b){
        vector<ll> num = dec_to_base(n, b);
        ll tmp = 0ll;
        for(ll x : num){
            tmp += x;
        }
        if(!prime(tmp)){
            cout << "NOT\n";
            return 0;
        }
    }
    cout << "YES\n";
}
