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

string S;
int n;

map<string,int> m;

vector<vector<string> > W(char x,vector<string> v){
	vector<vector<string> > d,p;
	vector<string> q;
	if(v.size() == 1){
		d.push_back(v);
		return d;
	}else{
		q = v;
		q.erase(q.begin());
		d = W(x,q);
		for(int i=0;i<d.size();++i){
			vector<string> z=d[i];
			z[0]=v[0]+x+z[0];
			p.push_back(z);
		}for(int i=0;i<d.size();++i){
			vector<string> z=d[i];
			z.insert(z.begin(),v[0]);
			p.push_back(z);
		}return p;
	}
}

vector<vector<string> > G(char c, string x){
	vector<string> v;
	string a = "";
	for(int i=0;i<x.size();++i){
		if(x[i]==c){
			if(a.size()>0){
				v.push_back(a);
				a = "";
			}else{
				a = "";
			}
		}else{
			a+=x[i];
		}
	}if(a.size()>0)
		v.push_back(a);
	return W(c,v);
	
}

int F(string x){
	if(x.size()<=2)
		return x.size();
	if(m[x]!=0)
		return m[x];
	int minn = x.size();
	for(int i=0;i<x.size();++i){
		for(int j=i;j<x.size();++j){
			if(x[i]==x[j]){
				int before=0,after=0,split=0;
				if((j-i)>1)
					split+=F(x.substr(i+1,(j-i-1)));
				if(i>0)
				   before = F(x.substr(0,i));
				if(j<(x.size()-1))
				   after = F(x.substr(j+1,(x.size()-j-1)));
				minn=min(minn,before + after + split);
			}
		}
	}
	return m[x] = 1+minn;
}

int main(){
	srand (time(NULL));
	cin >> n;
	for(int i=0;i<n;++i){
		char x;
		cin >> x;
		if(S[S.size()-1]!=x)
			S+=x;
	}
	cout << F(S);
}
