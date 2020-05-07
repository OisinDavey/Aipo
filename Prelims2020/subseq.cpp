#include<bits/stdc++.h>

//clock_t tStart = clock();	
//printf("Time taken: %.2fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);

#define rep(j,n) for(int i=j;i<n;i++)
#define rup(k,n) for(int j=k;j<n;j++)
#define pb push_back
#define MX_N 100001
#define INF 100000000
#define mod7 1000000007
#define f first
#define s second
#define LSB(i) ((i) & -(i)) 

typedef long double lf;
typedef long long int ll;
typedef unsigned long long int ull;

ll gcd(ull a, ull b){return (a==0)?b:gcd(b%a,a);}
ll lcm(ull a, ull b){return a*(b/gcd(a,b));}
int trinum(int x){return x*(x+1)/2;}
int kx[8] = {+2,+2,-2,-2,+1,+1,-1,-1};
int ky[8] = {+1,-1,+1,-1,+2,-2,+2,-2};
int d9x[9] = {+1,+1,+1,+0,+0,+0,-1,-1,-1};
int d9y[9] = {+1,+0,-1,+1,+0,-1,+1,+0,-1};

using namespace std;

int main(){
	srand (time(NULL));
	//ios_base::sync_with_stdio(false);
    //cin.tie(NULL);
	ll n,k,count,c=0LL;
	cin >> n >> k;
	ll a[n];
	for(int i=0;i<n;++i)
		cin >> a[i];
	sort(a,a+n);
	count=1LL;
	c=a[0];
	if(k==1LL){
		cout << a[0];
		return 0;
	}
	for(int i=1;i<n;++i){
		if(a[i]<=(a[i-1]+5)){
			count++;
			c+=a[i];
			if(count==k){
				cout << fixed << c;
				return 0;
			}
		}else{
			c=a[i];
			count = 1LL;
		}
	}cout << -1;
}