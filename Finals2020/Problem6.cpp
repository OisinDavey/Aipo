#include<bits/stdc++.h>

#define INF 100000000
#define mod7 1000000007

typedef long double lf;
typedef long long int ll;
typedef unsigned long long int ull;

using namespace std;

int N;

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int IDs=0;
	cin >> N;
	string s;
	getline(cin,s);
	getline(cin,s);
	stack<int> stak;
	map<int,int> m;
	map<int,int> id;
	map<int,bool> redundant;
	for(int i=0;i<N;++i){
		redundant[i] = 0;
		if(s[i] == '('){
			stak.push(i);
		}else if(s[i] == ')'){
			m[i] = stak.top();
			m[stak.top()] = i;
			id[i] = IDs;
			id[stak.top()] = IDs;
			IDs++;
			stak.pop();
		}
	}
	
	for(int i=0;i<N;++i){
		if(s[i] == ')'){
			int l = m[i];
			int r = i;
			if(s[l+1] == '(' && s[r-1] == ')'){
				if(id[l+1] == id[r-1]){
					redundant[l] = 1;
					redundant[r] = 1;
				}
			}
		}
	}
	
	for(int i=0;i<N;++i){
		if(!redundant[i])
			cout << s[i];
	}
}