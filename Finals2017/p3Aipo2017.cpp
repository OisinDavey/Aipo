#include <iostream>
#include <algorithm>
#include<string>
#include <vector>
using namespace std;
char a[1000][1000];int c=0;char d,k;
int flood(int x,int y){
	a[x][y]=d;c++;
	if(a[x-1][y]==k&&(x>0)){flood(x-1,y);}
	if(a[x][y-1]==k&&(y>0)){flood(x,y-1);}
	if(a[x][y+1]==k){flood(x,y+1);}
	if(a[x+1][y]==k){flood(x+1,y);}
}
int main(){
	int r,c,x,y;
	cin >> r >> c;
	for(int i=0;i<r;i++){
		for(int j=0;j<c;j++){
			cin >> a[i][j];
		}
	}
	cin >> x >> y >> d;
	k=a[x][y];
	flood(x,y);
	for(int i=0;i<r;i++){
		for(int j=0;j<c;j++){
			cout << a[i][j];
		}cout << endl;
	}
}