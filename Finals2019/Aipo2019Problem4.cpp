#include<bits/stdc++.h>

typedef long long int ll;

using namespace std;

string alph = "abcdefghijklmnopqrstuvwxyz";
map<char,bool> isalph;
int main(){
	for(int i=0;i<alph.size();i++){
		isalph[alph[i]]=1;
	}
	int t;
	cin >> t;
	string test;
	getline(cin,test);
	while(t--){
		map<char,int> lett;
		int odd=0,even=0;
		string s;
		getline(cin,s);
		for(int i=0;i<s.size();i++){
			s[i]=tolower(s[i]);
			if(isalph[s[i]]){
				lett[s[i]]++;
			}
		}for(auto x:lett){
			//cout << x.first << ' ' << x.second << endl;
			if(x.second%2){
				odd++;
			}else{
				even++;
			}
		}if(odd>1){
			cout << 0 << endl;
			//cout << 0 << ' ' << odd << endl;
		}else{
			cout << 1 << endl;
		}
	}
}
