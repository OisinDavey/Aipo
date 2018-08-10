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

int b[8][8];

void f(int x,int y,int m){
	if(x<0||y<0||x>=8||y>=8)
		return;
	if(m >= b[x][y] && b[x][y]!= -1)
		return;
	b[x][y] = m;
	m++;
	f(x+1,y+2,m);
	f(x+1,y-2,m);
	f(x-1,y+2,m);
	f(x-1,y-2,m);
	f(x+2,y+1,m);
	f(x+2,y-1,m);
	f(x-2,y+1,m);
	f(x-2,y-1,m);
}

int main(){
	memset(b,-1,sizeof(b));
	char a1,a2;
	int  x1,x2,y1,y2;
	cin >> a1 >> x1 >> a2 >> x2;
	x1--,x2--;
	y1=(int)a1-(int)'a',y2=(int)a2-(int)'a';
	f(x1,y1,0);
	cout << b[x2][y2];
}