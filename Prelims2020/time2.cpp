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
	time_t Ts,Te;
	
	while(1){
			int yy ,MM ,dd ,hh, mm, ss=0;
			struct tm when = {0};

			scanf("%d-%d-%d %d:%d", &yy, &MM, &dd, &hh, &mm);

			when.tm_year = (yy-1900);
			when.tm_mon = (MM-1);
			when.tm_mday = dd;
			when.tm_hour = hh;
			when.tm_min = mm;
			when.tm_sec = ss;

			Ts = mktime(&when);
			break;
		}
	while(1){
			int yy ,MM ,dd ,hh, mm, ss=0;
			struct tm when = {0};

			scanf("%d-%d-%d %d:%d", &yy, &MM, &dd, &hh, &mm);

			when.tm_year = (yy-1900);
			when.tm_mon = (MM-1);
			when.tm_mday = dd;
			when.tm_hour = hh;
			when.tm_min = mm;
			when.tm_sec = ss;

			Te = mktime(&when);
			break;
		}
	
	int n;
	cin >> n;
	
	for(int i=0;i<n;++i){
		time_t Tx;
		while(1){
			int yy ,MM ,dd ,hh, mm, ss=0;
			struct tm when = {0};

			scanf("%d-%d-%d %d:%d", &yy, &MM, &dd, &hh, &mm);

			when.tm_year = (yy-1900);
			when.tm_mon = (MM-1);
			when.tm_mday = dd;
			when.tm_hour = hh;
			when.tm_min = mm;
			when.tm_sec = ss;

			Tx = mktime(&when);
			break;
		}
		
		if((Tx>=(Ts-3600))&&(Tx<=Ts)){
			cout << "Early";
		}else if((Tx<(Ts-3600))||(Tx>=Te)){
			cout << "Missed";
		}else if((Tx>Ts)&&(Tx<=(Ts+600))){
			cout << "On time";
		}else{
			cout << "Late";
		}cout << endl;
	}
}