#include <iostream>
#include <algorithm>
#include<string>
#include <vector>
using namespace std;
int main(){
	int f;
	cin >> f;vector<int> v;
	for(int g=0;g<f;g++){
		int l;bool c1=0,c2=0,c3=0,c4=0;
		cin >> l;
		if(l>=12){
			string s;string t="+_)(*&^%$#@!./,;{}";
			cin >> s;
			for(int i=0;i<l;i++){
				if(s[i]>='a'&&s[i]<='z'){
					c1=1;
				}
				if(s[i]>='A'&&s[i]<='Z'){
					c2=1;
				}
				if(s[i]>='0'&&s[i]<='9'){
					c3=1;
				}
				for(int j=0;j<18;j++){
					if(s[i]==t[j]){
						c4=1;break;
					}
				}
			}
			if(c1&&c2&&c3&&c4){cout << "valid\n";}
			else{cout << "invalid\n";}
		}else{string s;cin >> s;cout << "invalid\n";}
	}
}