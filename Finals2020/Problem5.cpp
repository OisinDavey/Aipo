#include<bits/stdc++.h>

#define INF 100000000
#define mod7 1000000007
#define MX_N 1000000

typedef long double lf;
typedef long long int ll;
typedef unsigned long long int ull;

using namespace std;

vector<string> godnames;

int pos(string a,string s){
	auto F = s.find(a);
	if(F!=string::npos)
		return F;
	else
		return -1;
}

string ceaser(string s, int rot){
	for(int i=0;i<s.size();++i)
		s[i] = (int)'A' + (char)(((int)s[i]-(int)'A'+rot)%26);
	return s;
}

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	string god;
	cin >> god;
	for(int i=0;i<26;++i)
		godnames.push_back(ceaser(god,i));
	
	int N;
	cin >> N;
	
	for(int i=0;i<N;++i){
		string a;
		cin >> a;
		for(int i=1;i<godnames.size();++i){
			if(pos(godnames[i],a) != -1){
				cout << i << endl;
				break;
			}
		}
	}
	
    return 0; 
}