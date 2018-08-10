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

ll a[1000];

ll f(ll x){
	return (x==0||x== -2) ? 1 : (a[x]==0) ? a[x]=((4*f(x-2)%1000000007)-(f(x-4)%(1000000007))) : a[x];
}

int main(){
	ll w;
	cin >> w;
	cout << ((w%2) ? 0 : f(w));
}
