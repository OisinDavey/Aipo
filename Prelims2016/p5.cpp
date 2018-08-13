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

int main(){
	int n,maxx=0,maxx2=0;
	cin >> n;
	int a[n],b[n];
	rep(0,n)
		cin >> a[i];
	for(int i=n-1;i>=0;i--){
		maxx=max(maxx,a[i]);
		maxx2=max(maxx2,maxx-a[i]);
	}
	cout << maxx2;
}