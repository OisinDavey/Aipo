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
	int n,p,c;
	cin >> n >> p;
	int a[p+1];
	int a2[p+1];
	memset(a2,0,sizeof(a2));
	rep(0,p)
		cin >> a[i];
	sort(a,a+p,greater<int>());
	a[p]=0;
	cin >> c;
	rep(0,c){
		int b;
		cin >> b;
		for(int j=0;j<=p;j++)
			if(b>=a[j]){
				a2[j]++;
				break;
			}
	}
	int d=0;
	rep(0,p+1){
		d+=a2[i];
		if(d==n){
			puts("yes");
			return 0;
		}
		if(d>n){
			puts("no");
			return 0;
		}
	}
	puts("no");
}