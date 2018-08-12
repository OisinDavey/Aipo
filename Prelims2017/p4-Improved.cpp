#include<bits/stdc++.h>
#define rep(j,n) for(int i=j;i<n;i++)
#define pb push_back
#define MX_N 100001
#define INF 10000000;
#define f first
#define s second
using namespace std;
typedef long double lf;
typedef long long int ll;

int main(){
	int n;
	cin >> n;
	queue<pair<int,int> > q;
	int a[n];
	rep(0,n){
		cin >> a[i];
		q.push(make_pair(a[i],i));
	}for(int i=1;q.size()>0;i++){
		if(q.front().f==1)
			a[q.front().s]=i;
		else
			q.front().f--,q.push(q.front());
		q.pop();
	}rep(0,n)
		cout << a[i] << ' ';
}