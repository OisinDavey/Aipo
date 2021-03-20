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


pair<int, int> par[1001][1001];
int set_size[1001][1001];

pair<int, int> find_set(pair<int, int> at){
    if(at == par[at.fi][at.se]){
        return at;
    }else{
        return par[at.fi][at.se] = find_set(par[at.fi][at.se]);
    }
}

void union_set(pair<int, int> A, pair<int, int> B){
    pair<int, int> tmp_A = find_set(A);
    pair<int, int> tmp_B = find_set(B);
    if(tmp_A == tmp_B){
        return;
    }
    par[tmp_B.fi][tmp_B.se] = tmp_A;
    set_size[tmp_A.fi][tmp_A.se] += set_size[tmp_B.fi][tmp_B.se];
    return;
}

int main(){
    int n, m;
    cin >> n >> m;
    bool board[n][m];
    for(int i=0;i<n;++i){
        for(int j=0;j<m;++j){
            cin >> board[i][j];
            par[i][j] = {i, j};
            set_size[i][j] = board[i][j];
        }
    }
    for(int i=0;i<n;++i){
        for(int j=0;j<m;++j){
            if(!board[i][j])continue;
            for(int q=0;q<4;++q){
                int _x = i + dx4[q];
                int _y = j + dy4[q];
                if(_x < 0 || _y < 0 || _x >= n || _y >= m) continue;
                if(!board[_x][_y])continue;
                union_set({_x, _y}, {i, j});
            }
        }
    }
    set<pair<int, int> > potential_boats;
    for(int i=0;i<n;++i){
        for(int j=0;j<m;++j){
            if(!board[i][j])continue;
            potential_boats.insert(find_set({i, j}));
        }
    }
    int ans = 0;
    for(auto& [x, y] : potential_boats){
        ans += (set_size[x][y] > 1);
    }
    cout << ans << endl;
}
