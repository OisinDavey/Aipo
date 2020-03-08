#include<bits/stdc++.h>

//clock_t tStart = clock();	
//printf("Time taken: %.2fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);

#define MX_N 500001
#define INF 100000000
#define mod7 1000000007
#define LSB(i) ((i) & -(i)) 
#define ii pair<int,int>

typedef long double lf;
typedef long long int ll;
typedef unsigned long long int ull;

ll gcd(ull a, ull b){return (a==0)?b:gcd(b%a,a);}
ll lcm(ull a, ull b){return a*(b/gcd(a,b));}
int kx[8] = {+2,+2,-2,-2,+1,+1,-1,-1};
int ky[8] = {+1,-1,+1,-1,+2,-2,+2,-2};
int d9x[9] = {+1,+1,+1,+0,+0,+0,-1,-1,-1};
int d9y[9] = {+1,+0,-1,+1,+0,-1,+1,+0,-1};

using namespace std;

ll N;

vector<ll> adjlist[MX_N];
vector<ll> revlist[MX_N];

bool visited[MX_N];
bool visited2[MX_N];

stack<int> stak;

vector<vector<int> > DCCs;

void dfs1(int at){
	visited[at] = 1;
	
	for(int neighbour : adjlist[at])
		if(!visited[neighbour])
			dfs1(neighbour);
	
	stak.push(at);
}

void dfs2(int at){
	visited2[at] = 1;
		
	for(int neighbour : revlist[at])
		if(!visited2[neighbour])
			dfs2(neighbour);
	
	DCCs[DCCs.size()-1].push_back(at);
}

int main(){
	//srand (time(NULL));
	//ios_base::sync_with_stdio(false);
    //cin.tie(NULL);
	cin >> N;
	string s;
	getline(cin,s);
	for(int i=0;i<N;++i){
		int a;
		cin >> a;
		int x;
		getline(cin,s);
		stringstream ss;
		ss.str(s);
		while(ss >> x){
			adjlist[a].push_back(x);
			revlist[x].push_back(a);
		}
	}
	
	for(int i=0;i<N;++i)
		if(!visited[i])
			dfs1(i);
	
	while(!stak.empty()){
		int at = stak.top();
		stak.pop();
		if(!visited2[at]){
			DCCs.push_back({});
			dfs2(at);
		}
	}
	
	for(auto a : DCCs){
		sort(a.begin(),a.end());
		for(int x : a)
			cout << x << ' ';
		cout << endl;
	}
}