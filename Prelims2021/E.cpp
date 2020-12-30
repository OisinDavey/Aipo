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

int V, Z, G;
int S;
char board[MX_N][MX_N];
vector<pair<int, int> > unknowns;

struct sight{
    int count;
    vector<pair<int, int> > path;
    sight* partner;
    pair<int, int> view_pos;
};

struct status{
    bool mirror;
    sight* V;
};

vector<status> statuses[MX_N][MX_N];
sight views[4][MX_N];     //Top, Bottom, Left, Right

bool in_bounds(pair<int, int> pos){
    return (pos.fi >=0 && pos.se >=0 && pos.fi < S && pos.se < S);
}

void inp(){
    cin >> V >> Z >> G;
    cin >> S >> S;
    for(int i=0;i<4;++i){
        for(int j=0;j<S;++j){
            views[i][j].partner = &(views[i][j]);
            views[i][j].view_pos = make_pair(i, j);
            cin >> views[i][j].count;
        }
    }
    for(int i=0;i<S;++i){
        for(int j=0;j<S;++j){
            cin >> board[i][j];
        }
    }

    //Fill out paths
    for(int i=0;i<4;++i){
        for(int j=0;j<S;++j){
            status tmp;
            tmp.V = &(views[i][j]);
            tmp.mirror = false;

            if(views[i][j].partner != &(views[i][j])){//Second time on this path
                views[i][j].path = views[i][j].partner->path;
                reverse(All(views[i][j].path));
                for(auto& pos : views[i][j].path){
                    if(board[pos.fi][pos.se] == '/' || board[pos.fi][pos.se] == '\\'){
                        tmp.mirror = true;
                    }
                    statuses[pos.fi][pos.se].pb(tmp);
                }
                continue;
            }

            //First time on this path
            int state = i;          //states: 0˅, 1˄, 2>, 3<
            int x, y;
            switch(i){
                case 0:
                    x = 0;
                    y = j;
                    break;
                case 1:
                    x = S-1;
                    y = j;
                    break;
                case 2:
                    x = j;
                    y = 0;
                    break;
                case 3:
                    x = j;
                    y = S-1;
                    break;
            }
            while(in_bounds(make_pair(x, y))){
                views[i][j].path.pb(make_pair(x, y));
                if(board[x][y] == '/'){
                    tmp.mirror = true;
                    switch(state){
                        case 0:
                            state = 3;
                            break;
                        case 1:
                            state = 2;
                            break;
                        case 2:
                            state = 1;
                            break;
                        case 3:
                            state = 0;
                            break;
                    }
                }else if(board[x][y] == '\\'){
                    tmp.mirror = true;
                    switch(state){
                        case 0:
                            state = 2;
                            break;
                        case 1:
                            state = 3;
                            break;
                        case 2:
                            state = 0;
                            break;
                        case 3:
                            state = 1;
                            break;
                    }
                }
                statuses[x][y].pb(tmp);
                switch(state){
                    case 0:
                        ++x;
                        break;
                    case 1:
                        --x;
                        break;
                    case 2:
                        ++y;
                        break;
                    case 3:
                        --y;
                        break;
                }
            }
            if(x == -1){
                views[i][j].partner = &(views[0][y]);
                views[0][y].partner = &(views[i][j]);
            }else if(x == S){
                views[i][j].partner = &(views[1][y]);
                views[1][y].partner = &(views[i][j]);
            }else if(y == -1){
                views[i][j].partner = &(views[2][x]);
                views[2][x].partner = &(views[i][j]);
            }else if(y == S){
                views[i][j].partner = &(views[3][x]);
                views[3][x].partner = &(views[i][j]);
            }
        }
    }
    return;
}

bool cheq(){
    for(int i=0;i<4;++i){
        for(int j=0;j<S;++j){
            if(views[i][j].count != 0){
                return false;
            }
        }
    }
    return true;
}

void update(pair<int, int> position, char c){
    int x = position.fi;
    int y = position.se;
    if(c == 'Z'){
        --Z;
    }else if(c == 'V'){
        --V;
    }else{
        --G;
    }
    for(auto& stat : statuses[x][y]){
        if(c == 'Z'){
            stat.V->count -= 1;
        }else if(c == 'V' && stat.mirror == false){
            stat.V->count -= 1;
        }else if(c == 'G' && stat.mirror == true){
            stat.V->count -= 1;
        }
    }
    board[x][y] = c;
    return;
}

bool valid_spot(pair<int, int> position){
    int x = position.fi;
    int y = position.se;
    char c = board[x][y];
    for(auto& stat : statuses[x][y]){
        if(stat.V->count < 0){
            return false;
        }
    }
    return true;
}

void undate(pair<int, int> position){
    int x = position.fi;
    int y = position.se;
    char c = board[x][y];
    if(c == 'Z'){
        ++Z;
    }else if(c == 'V'){
        ++V;
    }else{
        ++G;
    }
    for(auto& stat : statuses[x][y]){
        if(c == 'Z'){
            stat.V->count += 1;
        }else if(c == 'V' && stat.mirror == false){
            stat.V->count += 1;
        }else if(c == 'G' && stat.mirror == true){
            stat.V->count += 1;
        }
    }
    board[x][y] = '.';
    return;
}

bool rec_brute(int pos){
    if(pos == unknowns.size()){
        return cheq();
    }
    int x = unknowns[pos].fi;
    int y = unknowns[pos].se;
    if(Z > 0){
        update(make_pair(x, y), 'Z');
        if(valid_spot(make_pair(x, y))){
            if(rec_brute(pos+1)){
                return true;
            }
        }
        undate(make_pair(x, y));
    }
    if(V > 0){
        update(make_pair(x, y), 'V');
        if(valid_spot(make_pair(x, y))){
            if(rec_brute(pos+1)){
                return true;
            }
        }
        undate(make_pair(x, y));
    }
    if(G > 0){
        update(make_pair(x, y), 'G');
        if(valid_spot(make_pair(x, y))){
            if(rec_brute(pos+1)){
                return true;
            }
        }
        undate(make_pair(x, y));
    }
    return false;
}

void brute(){
    for(int i=0;i<S;++i){
        for(int j=0;j<S;++j){
            if(board[i][j] == '.'){
                unknowns.pb(make_pair(i, j));
            }
        }
    }
    rec_brute(0);
    return;
}

void know(){
    //Repeated zeroes strat
    while(true){
        bool improved = false;
        for(int i=0;i<4;++i){
            for(int j=0;j<S;++j){
                if(views[i][j].count != 0){
                    continue;
                }
                bool mir = false;
                for(auto& pos : views[i][j].path){
                    int x = pos.fi;
                    int y = pos.se;
                    if(board[x][y] == '/' || board[x][y] == '\\'){
                        mir = true;
                    }else if(mir && board[x][y] == '.'){
                        update(make_pair(x, y), 'V');
                        improved = true;
                    }else if(!mir && board[x][y] == '.'){
                        update(make_pair(x, y), 'G');
                        improved = true;
                    }
                }
            }
        }
        if(!improved){
            break;
        }
    }
    return;
}

int main(){
    inp();
    know();
    brute();
    for(int i=0;i<S;++i){
        for(int j=0;j<S;++j){
            cout << board[i][j];
        }
        cout << endl;
    }
    return 0;
}
