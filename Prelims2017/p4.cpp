#include <iostream>
#include <queue>
#include <cmath>
using namespace std;
int main() {
	int N;int j=0;int f=0;
	cin >> N;
	queue<int> Q,w,O;//What's this?
	int arr [N];
	while(j<N){
		int cur;
		cin >> cur;
		Q.push(cur);
		O.push(j+1);
		f = cur+f;
		j++;
	}
	for(int k=0;k<f;k++){
		if(Q.front()>1){
			Q.front() =Q.front()-1;
			Q.push(Q.front());
			Q.pop();
			O.push(O.front());
			O.pop();
		}
		else if(Q.front()==1){
			Q.pop();
			arr[O.front()] = k+1;
			O.pop();
		}
	}
	for(int i=1;i<=N;i++){
		cout << arr[i] << ' ';
	}
}