#include<bits/stdc++.h>

typedef long long int ll;

using namespace std;

int main(){
	string s,a;
	cin >> s;
	a = s.substr(1,s.size()-1);
	bool x=(s[0]=='B'),y=(s[0]=='F'),z=(s[0]=='M');
	cout << s << ", " << s << ", bo-" << (x?"":"b") << a << endl;
	cout << "bo-na-na fanna, fo-" << (y?"":"f") << a << endl;
	cout << "fee fi mo-" << (z?"":"m") << a << ", " << s << "!\n";
}
