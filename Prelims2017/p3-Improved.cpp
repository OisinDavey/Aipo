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

int main(){
	map<int,vector<int> > m;
	int n,k,c=0;
	cin >> n >> k;
	int a[n];
	rep(0,n){
		cin >> a[i];
		m[a[i]].pb(i);
	}rep(0,n)
		for(int j=0;j<m[k-a[i]].size();j++)
			c+=(m[k-a[i]][j]>i);
	cout << c;
}