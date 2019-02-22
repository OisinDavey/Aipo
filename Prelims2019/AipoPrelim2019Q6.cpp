#include<bits/stdc++.h>

#define MX_N 202
#define INF 1234567891
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
typedef pair<double,double> dd;

int dx4[] = {0, 0, +1, -1};
int dy4[] = {+1, -1, 0, 0};
int dx8[] = {+1, 0, -1, 0, +1, +1, -1, -1};
int dy8[] = {0, +1, 0, -1, +1, -1, +1, -1};

struct line{
	double x1,y1,x2,y2,m,c;
	bool ass;
};

struct explosion{
	double x,y;
};

int main(){
	int n,r;
	cin >> n >> r;
	dd g[n];
	dd gb[n];
	bool gbd[n];
	memset(gbd,0,sizeof(gbd));
	line p[n];
	vector<explosion> exp;
	rep(0,n)
		cin >> g[i].fi >> g[i].se;
	rep(0,n)
		cin >> gb[i].fi >> gb[i].se;
	
	rep(0,n){
		int a,b;
		cin >> a >> b;
		p[i].x1=g[a].fi;
		p[i].y1=g[a].se;
		p[i].x2=gb[b].fi;
		p[i].y2=gb[b].se;
		if(p[i].x1==p[i].x2)
			p[i].ass=1;
		else{
			p[i].ass=0;
			p[i].m=(p[i].y1-p[i].y2)/(p[i].x1-p[i].x2);
			p[i].c=(-p[i].x1*p[i].m)+p[i].y1;
		}
	}
	
	rep(0,n){
		rup(i,n){
			explosion ss;
			if(p[i].ass){
				if(p[j].ass)
					continue;
				ss.x=p[i].x1;
			}else if(p[j].ass){
				ss.x=p[j].x1;
			}else{
				if(p[i].m==p[j].m)
					continue;
				ss.x=(p[i].c-p[j].c)/(p[j].m-p[i].m);
			}
			ss.y=(p[i].m*ss.x)+p[i].c;
			if(ss.x>=(min(p[i].x1,p[i].x2))&&ss.x<=(max(p[i].x1,p[i].x2))&&ss.y>=(min(p[i].y1,p[i].y2))&&ss.y<=(max(p[i].y1,p[i].y2)))
				if(ss.x>=(min(p[j].x1,p[j].x2))&&ss.x<=(max(p[j].x1,p[j].x2))&&ss.y>=(min(p[j].y1,p[j].y2))&&ss.y<=(max(p[j].y1,p[j].y2)))
					exp.pb(ss);
		}
	}
	
	int c=0;
	
	rep(0,n)
		rup(0,exp.size())
			if(sqrt( ( (gb[i].fi-exp[j].x)*(gb[i].fi-exp[j].x) )+( (gb[i].se-exp[j].y)*(gb[i].se-exp[j].y) ) )<=r){
				gbd[i]=1;
				c++;
				break;
			}
	
	cout << n-c;
}