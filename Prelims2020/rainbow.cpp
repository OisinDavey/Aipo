//
// ~oisín~ C++ Template
//

#include                <bits/stdc++.h>
#define MX_N            5001
#define INF             100000000
#define mod7            1000000007
#define modpi           314159
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

using namespace std;

int n;
int a[151];
int dp[151][151];

int F(int L, int R){
    if(dp[L][R] != -1)
        return dp[L][R];
    if(L == R)
        return dp[L][R] = 1;
    int minn = (INF);
    for(int i=L;i<=R;++i){
        int temp = 1;
        if(i > L)
            temp += F(L+1, i);
        temp += F(i+1, R);
        if(a[i+1]==a[L])
            --temp;
        minn = min(minn, temp);
    }
    return dp[L][R] = minn;
}

int main(){
    memset(dp, -1, sizeof(dp));
    cin >> n;
    for(int i=0;i<n;++i) cin >> a[i];
    cout << F(0, n-1) << endl;
}
