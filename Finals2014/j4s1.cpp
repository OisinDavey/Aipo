//
// Solved Equation, assuming that this works, no testcases to check against, 
// I claim the only "Over 9000" solution is 0 0 0, horizontal line through origin
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
    while(T--){
        int a, b, c;
        cin >> a >> b >> c;
        int tmp = b*b - 4*a*c;
        if(a == 0 && b == 0 && c == 0){
            cout << "Over 9000 solutions\n";
        }else if(a == 0 && b == 0){
            cout << "No solution\n";
        }else if(a == 0){
            cout << "1 solution\n";
        }else if(tmp == 0){
            cout << "1 solution\n";
        }else if(tmp > 0){
            cout << "2 solutions\n";
        }else{
            cout << "No solution\n";
        }
    }
}
