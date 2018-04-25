#include <cstdio>
#include <string>
#include <iostream>
#include <cmath> 
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int main(){
	string a;
	cin >> a;
	for(int i=0;i<a.size();i++){
		if(a[i]=='A')cout << 'T';
		else if(a[i]=='T')cout << 'A';
		else if(a[i]=='C')cout << 'G';
		else cout << 'C';
	}
}