//
// Solved Years, under the impression that this works
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
    int n;
    cin >> n;
    int sum[2050];
    int seen[10];
    memset(sum, 0, sizeof(sum));
    for(int i=2014;i>=1000;--i){
        stringstream tmp;
        tmp << i;
        string x;
        tmp >> x;
        memset(seen, 0, sizeof(seen));
        for(char c : x){
            ++seen[(int)c-(int)'0'];
        }
        sum[i] = sum[i+1];
        for(int j=0;j<10;++j){
            if(seen[j] > 1){
                goto end_of_loop;
            }
        }
        ++sum[i];
        end_of_loop:;
    }
    for(int i=0;i<n;++i){
        int x;
        cin >> x;
        cout << sum[x] << endl;
    }
}
