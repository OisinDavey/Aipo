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

int dx4[] = {0, 0, +1, -1};
int dy4[] = {+1, -1, 0, 0};
int dx8[] = {+1, 0, -1, 0, +1, +1, -1, -1};
int dy8[] = {0, +1, 0, -1, +1, -1, +1, -1};

struct storm{
	int x,y,strength,day;
};

int main(){
	int d,n,s;
	cin >> d >> n >> s;
	ii t[n];//List of towns
	int ll[n];//level of towns
	memset(ll,0,sizeof(ll));
	storm l[s];//List of storms
	rep(0,n)
		cin >> t[i].fi >> t[i].se;
	rep(0,s){
		cin >> l[i].x >> l[i].y >> l[i].strength >> l[i].day;
		l[i].day--;
	}
	
	for(int k=0;k<d;k++){//every day
		rep(0,n){//every town
			ll[i]=max(0,ll[i]-1);
			rup(0,s){//relation to every storm
				if(l[j].day<=k){
					int x;
					x=abs(l[j].x-t[i].fi)+abs(l[j].y-t[i].se);//distance
					x=max(0,l[j].strength-x);//first day level
					x=max(0,x-(k-l[j].day));//current day level
					//cout << " __<" << x << ">__ ";
					ll[i]=ll[i]+x;
				}
			}
			cout << ll[i] << ' ';
		}cout << endl;
	}
}