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

/*int G(string s,char x){
	string v="";
	int c=0;
	vector<string> V;
	for(int i=0;i<s.size();++i){
		if(s[i]==x){
			V.push_back(v);
			v="";
		}else{
			v+=s[i];
		}
	}V.push_back(v);
	for(int i=0;i<V.size();++i){
		c+=F(V[i]);
	}return c+1;
}*/

ll F(string s){
	if(s=="")
		return 0;
	ll minn=1000000000;
	map<char,ll> m;
	for(int i=0;i<s.size();++i){
		if(m[s[i]]==0)
			m[s[i]]=1;
		else
			m[s[i]]++;
	}for(auto it = m.begin(); it != m.end();++it){
		char x = it->first;
		string v="";
		ll c=0;
		vector<string> V;
		for(int i=0;i<s.size();++i){
			if(s[i]==x){
				V.push_back(v);
				v="";
			}else
				v+=s[i];
		}V.push_back(v);
		for(int i=0;i<V.size();++i)
			c+=F(V[i]);
		minn = min(minn,c+1);
	}return minn;
}

int main(){
	srand (time(NULL));
	//ios_base::sync_with_stdio(false);
    //cin.tie(NULL);
	int n;
	cin >> n;
	string s="";
	for(int i=0;i<n;++i){
		char x;
		cin >> x;
		s+=x;
	}
	cout << F(s);
}