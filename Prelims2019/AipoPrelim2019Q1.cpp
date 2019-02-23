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

int main(){
	ll n;
	cin >> n;
	while(n--){
		ll t;
		int a=0,j=0;
		cin >> t;
		string s = bitset<32>(t).to_string();
		rep(0,s.size()){
			if(s[i]=='1'){
				j=i;
				break;
			}
		}	
		rep(j,s.size())
			(s[i]=='1')?a++:a--;
		cout << ((a==0)?0:((a>0)?1:-1)) << endl;
	}
	
}
