#include<bits/stdc++.h>
using namespace std;
int main(){
	string s[19]={"zero","one","two","three","four","five","six","seven","eight","nine","ten","eleven","twelve","thirteen","fourteen","fifteen","sixteen","seventeen","eighteen"};
	string a,b,c;
	int x,y;
	cin >> a >> b >> c;
	for(int i=0;i<19;i++){
		if(s[i]==a)
			x=i;
		if(s[i]==c)
			y=i;
	}
	cout << s[x+y];
}