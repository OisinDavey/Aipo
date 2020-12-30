//
// ~oisín~ C++ Template
//

#include                <bits/stdc++.h>
#define MX_N            100001
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

bitset<MX_N> sieve;
ll biggest_prime_factor[MX_N];
vector<ll> primes;

void fill_sieve(){
    sieve.set();
    sieve.flip();
    for(ll i=2LL;i<MX_N;++i){
        if(biggest_prime_factor[i] == 0){
            biggest_prime_factor[i] = i;
            sieve[i] = 1;
            primes.pb(i);
            for(ll j=2LL*i;j<MX_N;j+=i){
                biggest_prime_factor[j] = i;
            }
        }
    }
}

set<ll, greater<ll>> prime_factors(ll x){
    set<ll, greater<ll>> res;
    while(x > 1){
        res.insert(biggest_prime_factor[x]);
        x /= biggest_prime_factor[x];
    }
    return res;
}

bool is_palindrome(ll x){
    stringstream ss;
    ss << x;
    string s,a;
    ss >> s;
    a = s;
    reverse(All(a));
    return (s == a);
}

int main(){
    ll n;
    cin >> n;
    set<ll, greater<ll>> res;
    if(n < MX_N){//Log-linear growth
        fill_sieve();
        res = prime_factors(n);
    }else{//Square-root growth
        ll m = n;
        ll it = 2LL;
        while(m > 1LL){
            if(m % it == 0){
                m /= it;
                res.insert(it);
            }else{
                ++it;
            }
        }
    }
    for(ll f : res){
        if(is_palindrome(f)){
            cout << f << endl;
            return 0;
        }
    }
    cout << "-1\n";
}
