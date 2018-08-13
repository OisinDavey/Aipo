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
	map<string,bool> m;
	m["true"]=1,m["false"]=0;
	map<bool,string> n;
	n[1]="true",n[0]="false";
	string a,b,c;
	cin >> a >> b >> c;
	cout << ((b=="OR") ? n[m[a] || m[c]] : n[m[a] && m[c]]);
}