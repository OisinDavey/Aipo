#include<bits/stdc++.h>
#define rep(j,n) for(int i=j;i<n;i++)
#define pb push_back
#define MX_N 100001
#define INF 10000000;
#define f first
#define s second

using namespace std;

typedef long double lf;
typedef long long int ll;
typedef unsigned long long ull;

const ull mod = 1000000007;

map<int,vector<int> > m;
map<int,int> p;

void f(int ii,int x){
	p[ii]=x;
	rep(0,m[ii].size()) f(m[ii][i],x+1);
}

int main(){
	int n,kk=1,k;
	cin >> n;
	int a[n];
	rep(0,n){
		cin >> k;
		if(k == -1)
			kk=i+1;
		else
			m[k].pb(i+1);
	}
	f(kk,0);
	rep(1,n+1)
		cout << p[i] << endl;
}