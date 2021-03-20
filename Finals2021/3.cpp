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

int best_1d(vector<int>& v){
    int n = v.size();
    int pref[n];
    for(int i=0;i<n;++i){
        pref[i] = v[i];
        if(i > 0){
            pref[i] += pref[i-1];
        }
    }
    map<int, int> earliest;
    map<int, bool> seen;
    seen[0] = true;
    earliest[0] = -1;
    int ans = 0;
    for(int i=0;i<n;++i){
        if(!seen[pref[i]]){
            earliest[pref[i]] = i;
            seen[pref[i]] = true;
        }else{
            ans = max(ans, i-earliest[pref[i]]);
        }
    }
    return ans;
}

int main(){
    int n, m;
    cin >> n >> m;
    int board[n][m];
    for(int i=0;i<n;++i){
        for(int j=0;j<m;++j){
            int x;
            cin >> x;
            if(x == 0){
                board[i][j] = -1;
            }else{
                board[i][j] = +1;
            }
        }
    }
    int pref_rows[n][m];
    for(int i=0;i<n;++i){
        for(int j=0;j<m;++j){
            pref_rows[i][j] = board[i][j];
            if(j > 0){
                pref_rows[i][j] += pref_rows[i][j-1];
            }
        }
    }
    int ans = 0;
    for(int l=0;l<m;++l){
        for(int r=l;r<m;++r){
            vector<int> v(n);
            for(int i=0;i<n;++i){
                v[i] = pref_rows[i][r];
                if(l > 0){
                    v[i] -= pref_rows[i][l-1];
                }
            }
            int len = best_1d(v);
            ans = max(ans, len*(r-l+1));
        }
    }
    if(ans == 0){
        cout << "No possible chip\n";
    }else{
        cout << ans << endl;
    }
}
