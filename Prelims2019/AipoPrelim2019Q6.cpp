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
typedef pair<long double,long double> lff;

int dx4[] = {0, 0, +1, -1};
int dy4[] = {+1, -1, 0, 0};
int dx8[] = {+1, 0, -1, 0, +1, +1, -1, -1};
int dy8[] = {0, +1, 0, -1, +1, -1, +1, -1};

struct line{
	lf x1,y1,x2,y2,m,c;
	bool ass;
};

struct explosion{
	lf x,y;
};

int main(){
	int n;
	lf r;
	cin >> n >> r;
	
	lff g[n];//Ghosts
	lff gb[n];//Ghost Busters
	
	line p[n];//Lines of Fire
	vector<explosion> exp;//Explosion Centers
	
	rep(0,n)//Ghosts
		cin >> g[i].fi >> g[i].se;
	rep(0,n)//Ghost Busters
		cin >> gb[i].fi >> gb[i].se;
	
	rep(0,n){
		int a,b;//X Y Coordinates
		cin >> a >> b;
		
		p[i].x1=g[a].fi;
		p[i].y1=g[a].se;
		p[i].x2=gb[b].fi;
		p[i].y2=gb[b].se;
		
		if(p[i].x1==p[i].x2)//If Beam is Vertical
			p[i].ass=1;
		else{
			p[i].ass=0;
			
			lf t1=(p[i].y1-p[i].y2);
			lf t2=(p[i].x1-p[i].x2);
			p[i].m = t1/t2;//Slope
			
			p[i].c = p[i].y1-(p[i].x1*p[i].m);//C-Intersection
		}
	}
	
	rep(0,n){
		rup(i+1,n){
			explosion ss;
			if(p[i].ass){//Vertical line
				if(p[j].ass)//Parallel
					continue;
				ss.x=p[i].x1;//Intersection X & Y
				ss.y=(p[j].m*ss.x)+p[j].c;
			}
			
			else if(p[j].ass){//Vertical line
				ss.x=p[j].x1;//Intersection X & Y
				ss.y=(p[i].m*ss.x)+p[i].c;
			}
			
			else{//Two Non-Vertical lines
				if(p[i].m==p[j].m)//Parallel
					continue;
				ss.x=(p[i].c-p[j].c)/(p[j].m-p[i].m);//Intersection X & Y
				ss.y=(p[i].m*ss.x)+p[i].c;
			}
			
			if(ss.x>=(min(p[i].x1,p[i].x2)) && ss.x<=(max(p[i].x1,p[i].x2)) && ss.y>=(min(p[i].y1,p[i].y2)) && ss.y<=(max(p[i].y1,p[i].y2)))//If Within Range
				if(ss.x>=(min(p[j].x1,p[j].x2)) && ss.x<=(max(p[j].x1,p[j].x2)) && ss.y>=(min(p[j].y1,p[j].y2)) && ss.y<=(max(p[j].y1,p[j].y2)))//If Within Range
					exp.pb(ss);//Store Intersection as Explosion Centers
		}
	}
	
	int c=0;//Dead Ghost Busters
	
	rep(0,n)//Every Ghost Buster
		rup(0,exp.size())//Every Explosion
			if(sqrt( ( (gb[i].fi-exp[j].x)*(gb[i].fi-exp[j].x) )+( (gb[i].se-exp[j].y)*(gb[i].se-exp[j].y) ) )<r){//If Within Explosion Radius
				c++;
				break;
			}
	
	cout << n-c;//Output Number of Ghost Busters minus Amount Dead
	return 0;
}