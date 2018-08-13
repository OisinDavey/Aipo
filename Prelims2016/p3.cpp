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
	int n,i=0;
	cin >> n;
	cout << n << ' ';
	for(;n!=1;i++)
		cout << ((n%2) ? n = (n * 3) + 1 : n = n/2) << ' ';
}