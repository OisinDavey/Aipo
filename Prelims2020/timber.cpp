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

struct node{
	int value;
	vector<node*> kids;
};

node* A [1000000];

int fun(node* x){
	int maxx=0;
	for(int i=0;i<(x->kids.size());++i)
		maxx = max(maxx,fun(x->kids[i]));
	return maxx+1;
}

int main(){
	srand (time(NULL));
	//ios_base::sync_with_stdio(false);
    //cin.tie(NULL);
	int n;
	cin >> n;
	for(int i=0;i<(n+1);++i){
		A[i] = new node;
	}
	for(int i=0;i<n;++i){
		int x;
		cin >> x;
		if(x != -1){
			A[x]->kids.push_back((A[i+1]));
		}else{
			A[0]->kids.push_back((A[i+1]));
		}
	}cout << fun((A[0]))-2;
	//cout << A[5]->kids.size();
}