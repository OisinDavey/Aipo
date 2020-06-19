//
// Solved Cargo, it's just the knapsack problem which is the same as lucky tickets in the next year, O(n*m) time & O(n + m) space
// No available test cases so this is not debugged
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
    int cargo_size;
    int num_products;
    cin >> cargo_size >> num_products;
    ll dp[cargo_size + 1];
    int product_id[cargo_size + 1];
    memset(dp, 0, sizeof(dp));
    memset(product_id, -1, sizeof(product_id));
    pair<int, int> produce[num_products]; //Volume & Value
    for(int i=0;i<num_products;++i){
        cin >> produce[i].fi >> produce[i].se;
    }
    for(int i=0;i<=cargo_size;++i){
        for(int j=0;j<num_products;++j){
            pair<int, int> product = produce[j];
            if(i - product.fi < 0){
                continue;
            }
            ll tmp = dp[i-product.fi] + product.se;
            if(tmp > dp[i]){
                product_id[i] = j;
                dp[i] = tmp;
            }
        }
    }
    int cur_id = product_id[cargo_size];
    int cur_size = cargo_size;
    int num_used[num_products];
    memset(num_used, 0, sizeof(num_used));
    while(cur_id != -1){
        ++num_used[cur_id];
        cur_size -= produce[cur_id].fi;
        cur_id = product_id[cur_size];
    }
    cout << dp[cargo_size] << endl;
    for(int i=0;i<num_products;++i){
        cout << num_used[i] << endl;
    }
}
