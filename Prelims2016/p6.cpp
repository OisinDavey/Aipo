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

ull c[1000][1000];

ull choose(ull n,ull k){
	return (k>n)?0LL:(c[n][k]!=0)?c[n][k]:((k==0LL)||(k==n))?c[n][k]=1LL:c[n][k]=(choose(n-1LL,k-1LL)+choose(n-1LL,k))%mod; 
}


int main(){
	int t;
	cin >> t;
	rep(0,t){
		ull n,k;
		cin >> n >> k;
		cout << choose(n,k) << endl;
	}	
}