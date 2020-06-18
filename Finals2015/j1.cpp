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

int main(){
    char board[3][3];
    for(int i=0;i<3;++i){
        for(int j=0;j<3;++j){
            cin >> board[i][j];
        }
    }
    //Check Rows
    for(int i=0;i<3;++i){
        if(board[i][0] != '.' && board[i][0] == board[i][1] && board[i][1] == board[i][2]){
            cout << "YES\n";
            return 0;
        }
    }
    //Check Columns
    for(int i=0;i<3;++i){
        if(board[0][i] != '.' && board[0][i] == board[1][i] && board[1][i] == board[2][i]){
            cout << "YES\n";
            return 0;
        }
    }
    //Check Diagonals
    if(board[0][0] != '.' && board[0][0] == board[1][1] && board[1][1] == board[2][2]){
        cout << "YES\n";
        return 0;
    }
    if(board[0][2] != '.' && board[0][2] == board[1][1] && board[1][1] == board[2][0]){
        cout << "YES\n";
        return 0;
    }

    cout << "NO\n";
    return 0;
}
