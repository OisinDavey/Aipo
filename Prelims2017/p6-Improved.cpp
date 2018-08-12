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

map<int,pair<int,int> > m;

bool comp(int a,int b){
	return (m[a].f==m[b].f) ? (m[a].s < m[b].s) : (m[a].f > m[b].f) ;
}

int comp1(int a,int b){
	return (b==0) ? a : min(a,b) ;
}

int main(){
	int n,c;
	cin >> n >> c;
	int a[n];
	rep(0,n){
		cin >> a[i];
		m[a[i]].f++;
		m[a[i]].s=comp1(i+1,m[a[i]].s);
	}
	sort(a,a+n,comp);
	rep(0,n)
		cout << a[i] << ' ';
}