#include<bits/stdc++.h>

typedef long long int ll;

using namespace std;

int main(){
	string x;
	int n;
	cin >> n;
	getline(cin,x);
	x="abcdefghijklmnopqrstuvwxyz.";
	map<char,bool> m;
	map<string,int> M;
	for(int i=0;i<x.size();i++){
		m[x[i]]=1;
	}
	while(n--){
		string v="";
		string s;
		getline(cin,s);
		for(int i=0;i<s.size();i++){
			s[i]=(s[i]==' ')?'.':s[i];
		}for(int i=0;i<s.size();i++){
			s[i]=tolower(s[i]);
		}for(int i=0;i<s.size();i++){
			if(m[s[i]]){
				v+=s[i];
			}
		}M[v]++;
		cout << v;
		if(M[v]>1){
			cout << M[v];
		}cout << "@ucc.ie\n";
		
	}
}
