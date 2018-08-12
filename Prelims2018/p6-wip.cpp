#include<bits/stdc++.h>
#define rep(j,n) for(int i=j;i<n;i++)
#define pb push_back
#define MX_N 100001
#define INF 10000000;
#define f first
#define s second
using namespace std;
typedef long double lf;
typedef long long int ll;

map<char,char> m;
	
bool comp(string a,string b){
	return a.size() > b.size();
}

bool comp1(char a,char b){
	return (m[a]==b) ? 1 : 0;
}

string comp2(string a,string b){
	if(a.size()>b.size()) swap(a,b);
	vector<string > v;
	string l="";
	for(int i=0;i<a.size();i++){
		if(comp1(a[i],b[i])) l = l + (a[i]);
		else v.pb(l),l="";
	}
	b=b.substr(1,b.size()-1);
	v.pb(l),l="";
	for(int i=0;i<a.size();i++){
		if(comp1(a[i],b[i])) l = l + (a[i]);
		else v.pb(l),l="";
	}
	v.pb(l);
	sort(v.begin(),v.end(),comp);
	return v[0];
}

int main(){
	m['T']='A',m['A']='T',m['G']='C',m['C']='G';
	string a,b="";
	cin >> a;
	vector<string > v;
	for(int i=0;a.size()>0;i++){
		b = a[0] + b;
		a = a.substr(1,a.size()-1);
		v.pb(comp2(a,b));
	}
	sort(v.begin(),v.end(),comp);
	reverse(v[0].begin(),v[0].end());
	cout << v[0] << ' ';
	reverse(v[0].begin(),v[0].end());
	for(int i=0;i<v[0].size();i++){
		cout << m[v[0][i]];
	}
}