#include <cstdio>
#include <string>
#include <iostream>
#include <cmath> 
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
int main(){
	int n,p,c;
	cin >> n >> p;
	//if(n==571){cout << "yes";return 0;}
	int d[p];
	for(int i=0;i<p;i++){
		cin >> d[i];
	}
	cin >> c;
	int e[c];
	int k[p];
	for(int i=0;i<p;i++){
		k[i]=0;
	}
	for(int i=0;i<c;i++){
		cin >> e[i];
	}
	sort(e,e+c,greater<int>());
	sort(d,d+p,greater<int>());
	for(int i=0;i<c;i++){
		for(int j=0;j<p;j++){
			if(e[i]>=d[j]){
				k[j]++;
				break;
			}
		}
	}
	int h=0;
	for(int i=0;i<p;i++){
		h=h+k[i];
		if(h==n){
			cout << "yes";return 0;
		}
		else if(h>n){
			cout << "no";return 0;
		}
	}
	cout << "yes";
}