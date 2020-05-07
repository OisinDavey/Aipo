#include<bits/stdc++.h>

//clock_t tStart = clock();	
//printf("Time taken: %.2fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);

#define rep(j,n) for(int i=j;i<n;i++)
#define rup(k,n) for(int j=k;j<n;j++)
#define pb push_back
#define MX_N 100001
#define INF 100000000
#define mod7 1000000007
#define f first
#define s second
#define LSB(i) ((i) & -(i)) 

typedef long double lf;
typedef long long int ll;
typedef unsigned long long int ull;

ll gcd(ull a, ull b){return (a==0)?b:gcd(b%a,a);}
ll lcm(ull a, ull b){return a*(b/gcd(a,b));}
int trinum(int x){return x*(x+1)/2;}
int kx[8] = {+2,+2,-2,-2,+1,+1,-1,-1};
int ky[8] = {+1,-1,+1,-1,+2,-2,+2,-2};
int d9x[9] = {+1,+1,+1,+0,+0,+0,-1,-1,-1};
int d9y[9] = {+1,+0,-1,+1,+0,-1,+1,+0,-1};

using namespace std;

unordered_map<ll,vector<pair<ll,ll> > > rows,cols,NE,SE;

int main(){
	srand (time(NULL));
	//ios_base::sync_with_stdio(false);
    //cin.tie(NULL);
	ll n,q;
	cin >> n >> q;
	for(int i=0LL;i<q;++i){
		ll R,C;
		cin >> R >> C;
		rows[R-1LL].push_back({C-1LL,i});
		cols[C-1LL].push_back({R-1LL,i});
		NE[n+C-R-1LL].push_back({C-1LL,i});
		SE[n-C-R+1LL].push_back({R-1LL,i});
	}vector<pair<ll,ll> > V;
	for(auto it = rows.begin(); it != rows.end();++it){
		sort(it->second.begin(),it->second.end());
		for(ll i=0LL;i<(it->second.size()-1LL);++i){
			V.push_back({it->second[i].second+1LL,it->second[i+1LL].second+1LL});
		}
	}for(auto it = cols.begin(); it != cols.end();++it){
		sort(it->second.begin(),it->second.end());
		for(ll i=0LL;i<(it->second.size()-1LL);++i){
			V.push_back({it->second[i].second+1LL,it->second[i+1LL].second+1LL});
		}
	}for(auto it = NE.begin(); it != NE.end();++it){
		sort(it->second.begin(),it->second.end());
		for(ll i=0LL;i<(it->second.size()-1LL);++i){
			V.push_back({it->second[i].second+1LL,it->second[i+1LL].second+1LL});
		}
	}for(auto it = SE.begin(); it != SE.end();++it){
		sort(it->second.begin(),it->second.end());
		for(ll i=0LL;i<(it->second.size()-1LL);++i){
			V.push_back({it->second[i].second+1LL,it->second[i+1LL].second+1LL});
		}
	}cout << V.size() << endl;
	for(ll i=0LL;i<V.size();++i){
		if(V[i].second<V[i].first)
			swap(V[i].second,V[i].first);
	}sort(V.begin(),V.end());
	for(ll i=0LL;i<V.size();++i){
		cout << fixed << V[i].first << ' ' << V[i].second << endl;
	}
}