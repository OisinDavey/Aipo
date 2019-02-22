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

void AtoR(int A){
	map<int,string> cvt;
	cvt[1000] = "M"; cvt[900] = "CM"; cvt[500] = "D"; cvt[400] = "CD";
	cvt[100]  = "C"; cvt[90]  = "XC"; cvt[50]  = "L"; cvt[40]  = "XL";
	cvt[10]   = "X"; cvt[9]   = "IX"; cvt[5]   = "V"; cvt[4]   = "IV";
	cvt[1]     = "I";
	for(map<int, string>::reverse_iterator i = cvt.rbegin(); i!=cvt.rend(); i++)
		while(A >=i->first) {
			printf("%s", ((string)i->second).c_str());
			A -= i->first;
		}
	cout << ' ';
}

int main(){
	int n;
	cin >> n;
	while(n--){
		int a;
		cin >> a;
		AtoR(a);
	}
}
