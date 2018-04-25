#include <iostream>
#include <algorithm>
#include<string>
#include <vector>
using namespace std;
char a[201][201];int m,n,memo[201][201];
int flood(int x,int y){
	if(x==m-1&&y==n-1)return 1;int sum=0;
	if(memo[x][y]!=-1)return memo[x][y];
	if(y<m-1)if(a[x][y+1]=='.')sum=(sum+flood(x,y+1))%1000000007;
	if(x<n-1)if(a[x+1][y]=='.')sum=(sum+flood(x+1,y))%1000000007;
	return memo[x][y]=sum;
}
int main(){
	cin >> n >> m;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			memo[i][j]=-1;
		}
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin >> a[i][j];
		}
	}
	cout << flood(0,0)%1000000007 << endl;
}