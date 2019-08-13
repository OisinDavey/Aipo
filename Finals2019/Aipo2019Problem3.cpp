#include<bits/stdc++.h>

typedef long long int ll;

using namespace std;

int main(){
	int n,m,b=0;
	int maxx=0;
	cin >> n >> m;
	string s[m];
	queue<string> q;
	vector<string> v;
	for(int i=0;i<m;i++){
		cin >> s[i];
		int p = s[i].size();
		maxx=max(maxx,p);
		q.push(s[i]);
	}while(!q.empty()){
		string x=q.front();
		q.pop();
		if(q.empty()){
			v.push_back(x);
			break;
		}while(1){
			if(x.size() + 1 + q.front().size() <= maxx){
				x+=" ";
				x+=q.front();
				q.pop();
			}else{
				break;
			}
		}v.push_back(x);
	}for(int i=0;i<(maxx + !(maxx%2))+4;i++){
		cout << ((i%2)?' ':'*');
	}cout << endl;
	for(int i=0;i<v.size();i++){
		cout << "* " << v[i];
		for(int j=v[i].size();j<(maxx + !(maxx%2));j++){
			cout << " ";
		}cout << " *\n";
	}for(int i=0;i<(maxx + !(maxx%2))+4;i++){
		cout << ((i%2)?' ':'*');
	}cout << endl;
}
