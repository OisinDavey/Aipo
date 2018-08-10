#include<bits/stdc++.h>
#define rep(j,n) for(int i=j;i<n;i++)
#define pb push_back
#define MX_N 1001
#define INF 10000000;
#define f first
#define s second
using namespace std;
typedef long double lf;
typedef long long int ll;

int n,m;
char k;
char a[MX_N][MX_N];

void f(int x,int y,int c){
	if(a[x][y]!=k||x>=n||x<0||y>=m||y<0)
		return;
	a[x][y]=c;
	f(x+1,y,c);
	f(x,y+1,c);
	f(x-1,y,c);
	f(x,y-1,c);
	return;
}

int main(){
	cin >> n >> m;
	rep(0,n)
		for(int j=0;j<m;j++)
			cin >> a[i][j];
	int x,y;
	char c;
	cin >> x >> y >> c;
	k=a[x][y];
	f(x,y,c);
	rep(0,n){
		for(int j=0;j<m;j++)
			cout << a[i][j];
		cout << endl;
	}
}