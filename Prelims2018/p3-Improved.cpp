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
	map<char,char> m;
	m['T']='A',m['A']='T',m['G']='C',m['C']='G';
	string a;
	cin >> a;
	rep(0,a.size())
		cout << m[a[i]];
}