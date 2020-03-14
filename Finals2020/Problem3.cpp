#include<bits/stdc++.h>

#define INF 100000000
#define mod7 1000000007

typedef long double lf;
typedef long long int ll;
typedef unsigned long long int ull;

using namespace std;

int N;

bool a[2001][2001];

bool li[2001];

bool visited[2001];

int dfs(int at){
	visited[at] = 1;
	for(int i=0;i<N;++i){
		if(a[at][i]){
			if(visited[i] == 0){///Unvisited
				if(li[at] == 0){
					li[i] = 1;
				}else{
					li[i] = 0;
				}
			}
		}
	}for(int i=0;i<N;++i){
		if(a[at][i]){
			if(visited[i] == 0){///Unvisited
				dfs(i);
			}
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	for(int i=0;i<N;++i){
		visited[i] = 0;
	}
	cin >> N;
	for(int i=0;i<N;++i){
		for(int j=0;j<N;++j){
			cin >> a[i][j];
		}
	}
	
	for(int i=0;i<N;++i){
		if(visited[i] == 0){
			li[i] = 0;
			dfs(i);
		}
	}
	
	vector<int> list1;
	vector<int> list2;
	
	for(int i=0;i<N;++i){
		if(li[i] == 0)
			list1.push_back(i);
		else
			list2.push_back(i);
	}
	
	sort(list1.begin(),list1.end());
	sort(list2.begin(),list2.end());
	
	for(int x : list1){
		cout << x << ' ';
	}cout << endl;
	for(int x : list2){
		cout << x << ' ';
	}
}