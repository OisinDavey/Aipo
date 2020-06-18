//
// Solution to S3 - Domain clusters, the question is just Strongly Connected Components and can be solved with kosaraju's algorithm 
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

struct graph{
    vector<int> adj[MX_N];
    bool visited[MX_N];
};

//Global Variables
int N;
int E;
graph G;
graph GT;
stack<int> stak;
vector<vector<int> > SCCs;
vector<int> cur_SCC;

void DFS(graph& g, int at){//First Pass through normal graph
    if(g.visited[at] == true){
        return;
    }
    g.visited[at] = true;
    for(int to : g.adj[at]){
        DFS(g, to);
    }
    stak.push(at);
}

void find_SCCs(graph& g, int at){
    if(g.visited[at] == true){
        return;
    }
    g.visited[at] = true;
    cur_SCC.pb(at);
    for(int to : g.adj[at]){
        find_SCCs(g, to);
    }
    return;
}

int main(){
    cin >> N >> E;
    memset(G.visited, 0, sizeof(G.visited));
    memset(GT.visited, 0, sizeof(GT.visited));
    for(int i=0;i<E;++i){
        int u, v;
        cin >> u >> v;
        --u;
        --v;
        G.adj[u].pb(v);
        GT.adj[v].pb(u);
    }
    for(int i=0;i<N;++i){
        DFS(G, i);
    }
    while(!stak.empty()){
        int at = stak.top();
        stak.pop();
        if(GT.visited[at] == false){
            find_SCCs(GT, at);
            SCCs.pb(cur_SCC);
            cur_SCC = {};
        }
    }
    int ans = 0;
    for(auto v : SCCs){
        ans = max(ans, (int)v.size());
    }
    cout << ans << endl;
}
