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
	map<string,int> m;
	map<int,string> n;
	string a[20]={"zero","one","two","three","four","five","six","seven","eight","nine","ten","eleven","twelve","thirteen","fourteen","fifteen","sixteen","seventeen","eighteen"};
	rep(0,19){
		n[i]=a[i];
		m[a[i]]=i;
	}
	string x,y,z;
	cin >> x >> y >> z;
	cout << n[m[x]+m[z]];
}