#include<bits/stdc++.h>
#define rep(j,n) for(int i=j;i<n;i++)
#define pb push_back
#define MX_N 201
#define INF 10000000;
#define f first
#define s second
using namespace std;
typedef long double lf;
typedef long long int ll;

int n,m;
char a[MX_N][MX_N];
ll b[MX_N][MX_N];

ll f(int x,int y){
	return (x<0||x>=n||y<0||y>=m)?0:(b[x][y]!=0)?b[x][y]:(a[x][y]=='X')?b[x][y]=0:(x==n-1&&y==m-1)?1:b[x][y]=f(x+1,y)+f(x,y+1);
}

int main(){
	cin >> n >> m;
	rep(0,n)
		for(int j=0;j<m;j++)
			cin >> a[i][j];
	cout << f(0,0)%1000000007;
}