#include <cstdio>
#include <string>
#include <iostream>
#include <cmath> 
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
int f(int n,int b){
	vector<int> vect;
	int c=0;
	for(int i=0;n>0;i++){
		vect.push_back(n%b);
		n=n/b;
	}
	for(int i=0;i<vect.size();i++){
		if(vect[i]==4){
			c++;
		}
	}
	return c;
}
int main(){
	int n;
	cin >> n;
	int a[n];
	for(int i=0;i<=n;i++){
		a[i]=f(i,5);
	}
	sort(a,a+n);
	cout << a[n-1];
}