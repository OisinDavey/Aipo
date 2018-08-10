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

pair<int,int> a[MX_N];

int main(){
	int n;
	string m;
	cin >> n >> m;
	rep(0,n)
		a[(int)m[i]].f++;
	rep((int)'a',(int)'z'+1)
		a[i].s=i;
	sort(a+(int)'a',a+(int)'z'+1);
	printf("%c %d",(char) a[(int)'z'].s,a[(int)'z'].f);
}