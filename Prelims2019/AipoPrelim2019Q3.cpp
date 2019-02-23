#include<bits/stdc++.h>

#define MX_N 202
#define INF 12345678910
#define pi 3.14159265358979323846

#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define czek(n,i) ((n&(1<<i))?1:0)
#define rep(j,n) for(int i=j;i<n;i++)
#define revrep(j,n) for(int i=n-1;i>=j;i--)
#define rup(k,n) for(int j=k;j<n;j++)
#define pb push_back
#define fi first
#define se second
#define u_map unordered_map
#define gcd(a,b) __gcd(a,b)
#define lcm(a,b) (a*(b/gcd(a,b)))
#define sqr(a) ((a) * (a))

using namespace std;

typedef double d;
typedef long double lf;
typedef long long int ll;
typedef unsigned long long ull;
typedef pair<int,int> ii;
typedef pair<float,float> ff;

int x4[] = {0, 0, +1, -1};
int y4[] = {+1, -1, 0, 0};
int x8[] = {+1, 0, -1, 0, +1, +1, -1, -1};
int y8[] = {0, +1, 0, -1, +1, -1, +1, -1};

int n,m;

bool bound(int x, int y){
	return (x>=0&&x<n&&y>=0&&y<m);
	//return 1;
}

int main(){
	cin >> n >> m;
	char a[n][m];
	int b[n][m];
	memset(b,0,sizeof(b));
	rep(0,n)
		rup(0,m)
			cin >> a[i][j];
	rep(0,n)
		rup(0,m)
			if(a[i][j]=='x'){
				b[i][j] = -1;
				for(int k=0;k<8;k++)
					b[i+x8[k]][j+y8[k]]+=((a[i+x8[k]][j+y8[k]]!='x') && bound(i+x8[k],j+y8[k]));
			}
	rep(0,n){
		rup(0,m){
			if(a[i][j]== 'x')
				cout << "x ";
			else
				cout << b[i][j] << ' ';
		}cout << endl;
	}
	
}
