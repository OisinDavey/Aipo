#include<bits/stdc++.h>

#define INF 100000000
#define mod7 1000000007

typedef long double lf;
typedef long long int ll;
typedef unsigned long long int ull;

using namespace std;

ll L=0,G=0,B=0;

struct node{
	bool swi;
	bool bulb;
	bool gate;
	
	bool val;
	
	ll type;
	
	ll id;
	
	vector<ll> inputs;
};

//map<ll,node*> m;
node* m[150001];

vector<node*> bulbs = {};

vector<node*> topso = {};

//map<node*,bool> vis;
bool vis[150001];

void dfs(node* at){
	vis[at->id] = 1;
	for(ll i=0;i<at->inputs.size();++i)
		if(!vis[m[at->inputs[i]]->id])
			dfs(m[at->inputs[i]]);
	topso.push_back(at);
	return;
}

struct comp{
	bool operator()(node* a, node* b){
		return a->id < b->id;
	}
};

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	cin >> L >> B >> G;
	
	for(int i=0;i<L;++i){
		ll a;
		bool b;
		cin >> a >> b;
		node* x = new node;
		vis[a] = 0;
		x->id = a;
		x->swi=1;
		x->bulb=0;
		x->gate=0;
		x->val = b;
		m[a] = x;
		x->inputs = {};
	}
	
	for(int i=0;i<B;++i){
		ll a,b;
		cin >> a >> b;
		node* x = new node;
		vis[a] = 0;
		x->id = a;
		x->swi=0;
		x->bulb=1;
		x->gate=0;
		x->val = 0;
		m[a] = x;
		x->inputs = {b};
		bulbs.push_back(x);
	}
	
	for(int i=0;i<G;++i){
		ll a,b,c,d;
		cin >> a >> b >> c >> d;
		node* x = new node;
		vis[a] = 0;
		x->id = a;
		x->swi=0;
		x->bulb=0;
		x->gate=1;
		x->val = 0;
		m[a] = x;
		x->inputs = {b,c};
		x->type = d;
	}
	
	if(B == 0)
		return 0;
	
	for(int i=0;i<B;++i)
		if(!vis[bulbs[i]->id])
			dfs(bulbs[i]);
	
	for(node* x : topso){
		if(x->bulb)
			x->val = m[x->inputs[0]]->val;
		else if(x->gate){
			if(x->type == 1)
				x->val = (m[x->inputs[0]]->val && m[x->inputs[1]]->val);
			else if(x->type == 2)
				x->val = (m[x->inputs[0]]->val || m[x->inputs[1]]->val);
			else if(x->type == 3)
				x->val = (m[x->inputs[0]]->val ^ m[x->inputs[1]]->val);
			else if(x->type == 4)
				x->val = !(m[x->inputs[0]]->val || m[x->inputs[1]]->val);
			else if(x->type == 5)
				x->val = !(m[x->inputs[0]]->val && m[x->inputs[1]]->val);
		}
	}
	
	sort(bulbs.begin(),bulbs.end(),comp());
	
	for(node* x : bulbs)
		cout << x->val << ' ';
	
	return 0;
}