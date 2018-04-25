#include <iostream>
#include <algorithm>
#include<string>
#include <vector>
using namespace std;
int main(){
	string s;int bla;
	cin >> bla >> s;
	int a[26][2],cur=0,acur=0;
	for(int d=0;d<26;d++){
		a[d][0]=d;
		a[d][1]=0;
	}
	for(int i=0;i<s.size();i++){
		for(int j=0;j<26;j++){
			if(s[i]==(char)(a[j][0]+97)){
				a[j][1]++;break;
			}
		}
	}
	for(int i=0;i<26;i++){
		if(a[i][1]>cur){acur=a[i][0];cur=a[i][1];}
	}
	cout  << (char)(acur+97) << ' ' << cur;
}