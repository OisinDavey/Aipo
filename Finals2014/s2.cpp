//
// Solved Manhattan, At least I'm pretty sure I have, no testcases were available, my solution works like this
// I claim that for any invalid board there exists a row or column containing something like ****...**
// If any row / column like this exists, to get from the first black squares to the second we will have to make 3 moves
// I also claim that this is an if and only if situation
// Any other squares that cannot be reached in 2 types of moves pass thorugh this type of setup I think
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
    FastIO;
    int T;
    cin >> T;
    for(int I=0;I<T;++I){
        cout << "Room " << I+1 << ": ";
        int n, m;
        cin >> n >> m;
        bool board[n][m];
        char tmp;
        for(int i=0;i<n;++i){
            for(int j=0;j<m;++j){
                cin >> tmp;
                board[i][j] = (tmp == '*')?1:0;
            }
        }
        vector<bool> row_abv[m];
        vector<bool> col_abv[n];
        for(int i=0;i<n;++i){
            col_abv[i].pb(board[i][0]);
            for(int j=1;j<m;++j){
                if(board[i][j] ^ board[i][j-1]){
                    col_abv[i].pb(board[i][j]);
                }
            }
        }
        for(int j=0;j<m;++j){
            row_abv[j].pb(board[0][j]);
            for(int i=1;i<n;++i){
                if(board[i][j] ^ board[i-1][j]){
                    row_abv[j].pb(board[i][j]);
                }
            }
        }
        for(int i=0;i<n;++i){
            for(int j=2;j<col_abv[i].size();++j){
                if(col_abv[i][j-2] == true && col_abv[i][j-1] == false && col_abv[i][j] == true){
                    cout << "NO\n";
                    goto end_of_loop;
                }
            }
        }
        for(int j=0;j<m;++j){
            for(int i=2;i<row_abv[j].size();++i){
                if(row_abv[j][i-2] == true && row_abv[j][i-1] == false && row_abv[j][i] == true){
                    cout << "NO\n";
                    goto end_of_loop;
                }
            }
        }
        cout << "YES\n";
        end_of_loop:;
    }
}
