//
// Solved Fib3, Although there is a trivial solution where you just take the ceiling of n/2, that feels uninspired
// This problem can be properly simulated in O(logN * 9) time using binary matrix exponentiation
// Better practice for me to do it this way
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

struct matrix{
    vector<vector<ll> > val;
    int width;
    int height;
};

matrix operator*(matrix& a, matrix& b){
    matrix result;
    result.height = a.height;
    result.width = b.width;
    int K = a.width;
    vector<vector<ll> > tmp (result.height, vector<ll> (result.width, 0LL));
    result.val = tmp;
    for(int i=0;i<a.height;++i){
        for(int j=0;j<a.width;++j){
            for(int k=0;k<K;++k){
                result.val[i][j] += a.val[i][k] * b.val[k][j];
            }
        }
    }
    return result;
}

ostream& operator<<(ostream& os, const matrix& a){
    for(int i=0;i<a.height;++i){
        for(int j=0;j<a.width;++j){
            os << a.val[i][j] << ' ';
        }
        os << endl;
    }
    return os;
}

matrix Z;

matrix ID_3;

matrix mat_binpow(matrix& a, ll expo){
    if(expo == 0){
        return ID_3;
    }
    if(expo == 1){
        return a;
    }
    matrix tmp = mat_binpow(a, expo/2);
    tmp = tmp * tmp;
    if(expo % 2 == 1){
        tmp = tmp * a;
    }
    return tmp;
}

int main(){
    Z.val = { {1, 1, -1}, {1, 0, 0}, {0, 1, 0} };
    Z.width = 3;
    Z.height = 3;
    ID_3.val = { {1, 0, 0}, {0, 1, 0}, {0, 0, 1} };
    ID_3.height = 3;
    ID_3.width = 3;
    int T;
    cin >> T;
    while(T--){
        ll n;
        cin >> n;
        matrix tmp = mat_binpow(Z, n-2);
        cout << tmp.val[0][0] + tmp.val[0][1] << endl;
    }
}
