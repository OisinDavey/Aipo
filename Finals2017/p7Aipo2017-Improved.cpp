#include<bits/stdc++.h>
#define rep(j,n) for(int i=j;i<n;i++)
#define pb push_back
#define MX_N 1000001
#define INF 10000000;
#define f first
#define s second
using namespace std;
typedef long double lf;
typedef long long int ll;

ll n,m;
ll a[MX_N*4];
pair<ll,ll> p[MX_N*4];

void s(ll jump) {
 for(ll i=0;i<n;i+=jump)
   a[i+m]++;
}

ll comp(ll x,ll y){///Min Plus Discrepancy
	return (x == -1) ? y : (y == -1) ? x : x + y;
}

ll fill(ll x){///Fill Values Into Trees
	return (x<m) ? a[x] = comp(fill(x*2),fill(x*2+1)) : a[x];
}

pair<ll,ll> fill2(ll x){///Fill In Ranges Covered By Vertex
	return (x<m) ? p[x]=make_pair(fill2(x*2).f,fill2(x*2+1).s) : p[x]=make_pair(x-m+1,x-m+1);
}

ll query(ll k,ll x,ll y){///Query Comp Of Range From x to y
	return (p[k].f>=x&&y>=p[k].s) ? a[k] : (p[k].s<x||p[k].f>y) ? -1 : comp(query(k*2,x,y),query(k*2+1,x,y));
}

int main(){
	ll k,z,q;
	cin >> n >> k;
	m=pow(2,ceil(log2(n)));
	rep(0,k){
		cin >> z;
		s(z);
	}
	fill(1);
	fill2(1);
	cin >> q;
	rep(0,q){
		ll g,h;
		cin >> g >> h;
		cout << query(1,g+1,h+1) << endl;
	}
	
}