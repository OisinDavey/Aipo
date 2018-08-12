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
    int n,m;
	cin >> n;
	string a[n];
	rep(0,n)
		cin >> a[i];
	cin >> m;
	string b[m];
	rep(0,m)
		cin >> b[i];
	sort(a,a+n);
	sort(b,b+m);
	rep(0,n)
		for(int j=0;j<m;j++)
			printf("%s, I am your %s.\n",a[i].c_str(),b[j].c_str());
}