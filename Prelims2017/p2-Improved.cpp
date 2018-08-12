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
	int a,b,g,k=0;
	string s;
	cin >> a >> b >> g;
	rep(0,a){
		cin >> s;
		m[s]=1;
	}rep(0,b){
		cin >> s;
		m[s]=0;
	}rep(0,g){
		cin >> s;
		(m[s]) ? k++ : k--;
	}
	cout << ((k==0) ? "TIE\n" : (k>0) ? "A\n" : "B\n");
}