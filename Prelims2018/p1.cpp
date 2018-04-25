#include <cstdio>
#include <string>
#include <iostream>
#include <cmath> 
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
int main(){
	int c,r;
	cin >> c;
	vector <string> v;
	for(int i=0;i<c;i++){
		string f;
		cin >> f;
		v.push_back(f);
	}
	cin >> r;
	vector <string> s;
	for(int i=0;i<r;i++){
		string f;
		cin >> f;
		s.push_back(f);
	}
	sort(v.begin(),v.end());
	sort(s.begin(),s.end());
	for(int i=0;i<c;i++){
		for(int j=0;j<r;j++){
			cout << v[i] << ", I am your " << s[j] << '.' << endl;
		}
	}
}