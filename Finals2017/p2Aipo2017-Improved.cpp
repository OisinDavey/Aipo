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

map<char,bool> m;

string g="+_)(*&^%$#@!./,;{}";

int main(){
	rep(0,g.size())
		m[g[i]]=1;
	int T;
	cin >> T;
	for(int gg=0;gg<T;gg++){
		int l;
		cin >> l;
		string s;
		cin >> s;
		bool c[6];
		memset(c,0,sizeof(c));
		if(l>=12)c[0]=1;
		rep(0,s.size()){
			if(isdigit(s[i]))c[1]=1;
			if(s[i]==tolower(s[i]))c[2]=1;
			if(s[i]==toupper(s[i]))c[3]=1;
			if(m[s[i]])c[4]=1;
		}
		c[5]=1;
		rep(0,5)
			c[5]=c[i]&&c[5];
		cout << ((c[5]) ? "valid\n" : "invalid\n" );
	}
}