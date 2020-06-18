//
// Solved S2 Lucky Tickets to 100%, using dp in O(N^2) time and O(N) space 
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
    string c;
    cin >> c;
    ifstream ifs ("test_cases/s2/test." + c + ".in", ifstream::in);
    ofstream ofs ("tmp/" + c + ".out", ofstream::out);
    int T;
    ifs >> T;
    for(int I=1;I<=T;++I){
        ll prev[3001];
        ll cur[3001];
        memset(prev, 0, sizeof(prev));
        memset(cur, 0, sizeof(cur));
        int n;
        ifs >> n;
        for(int i=0;i<=9;++i){
            prev[i] = 1;
        }
        for(int i=1;i<n;++i){
            memset(cur, 0, sizeof(cur));
            for(int j=3000;j>=0;--j){
                for(int k=0;k<=9;++k){
                    cur[j] += (((j-k)>=0)?prev[j-k]:0);
                    cur[j] %= mod7;
                }
            }
            memcpy(prev, cur, sizeof(prev));
        }
        ll ans = 0;
        for(int j=0;j<3000;++j){
            ll tmp = prev[j] * prev[j];
            tmp %= mod7;
            ans += tmp;
            ans %= mod7;
        }
        ofs << "Case #" << I << ": " << ans << endl;
    }
}
