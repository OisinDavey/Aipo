//
// ~oisín~ C++ Template
//

#include                <bits/stdc++.h>
#define MX_N            5001
#define mp              make_pair
#define mod7            1000000007
#define modpi           314159
#define PI              3.141592653589793238
#define pb              push_back
#define FastIO          ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define All(a)          a.begin(),a.end()
#define fi              first
#define se              second
#define ll              long long int
#define ull             unsigned long long int

int kx[8]  =            {+2, +2, -2, -2, +1, +1, -1, -1};
int ky[8]  =            {+1, -1, +1, -1, +2, -2, +2, -2};
int d9x[9] =            {+1, +1, +1, +0, +0, +0, -1, -1, -1};
int d9y[9] =            {+1, +0, -1, +1, +0, -1, +1, +0, -1};
int dx4[4] =            {+0, +0, +1, -1};
int dy4[4] =            {+1, -1, +0, +0};

ll gcd(ull a, ull b){
    return (a==0)?b:gcd(b%a,a);
}

ll lcm(ull a, ull b){
    return a*(b/gcd(a,b));
}

const long long INF = 1e18;

using namespace std;

int n;

bool failed_ind[2000001];
int fail_fentree[2000001];

void fen_update(int f_pos){
    ++f_pos;
    while(f_pos < 2000001){
        ++fail_fentree[f_pos];
        f_pos += (f_pos & (-f_pos));
    }
}

int pre_fails(int pos){
    ++pos;
    int ans = 0;
    while(pos > 0){
        ans += fail_fentree[pos];
        pos -= (pos & (-pos));
    }
    return ans;
}

int fake_ind(int ind){
    return ind - pre_fails(ind);
}

int translate_ind(int ind){
    int L = 0;
    int R = n-1;
    while(L < R){
        int M = L + (R-L)/2;
        if(fake_ind(M) < ind){
            L = M+1;
        }else{
            R = M;
        }
    }
    return L;
}

struct node{
    node* l;
    node* r;
    int L;
    int R;
    ll sum;
    ll minn;
};

ll line[2000001];

node* build(int L, int R){
    node* at = new node;
    at->L = L;
    at->R = R;
    if(L == R){
        at->l = nullptr;
        at->r = nullptr;
        at->sum = line[L];
        at->minn = line[L];
    }else{
        int M = L + (R - L)/2;
        at->l = build(L, M);
        at->r = build(M+1, R);
        at->sum = at->l->sum + at->r->sum;
        at->minn = min(at->l->minn, at->r->minn);
    }
    return at;
}

void fail_point(node* at, int pos){
    if(!(at->L <= pos && pos <= at->R))return;
    if(at->L == at->R){
        at->sum = 0;
        at->minn = INF;
    }else{
        fail_point(at->l, pos);
        fail_point(at->r, pos);
        at->sum = at->l->sum + at->r->sum;
        at->minn = min(at->l->minn, at->r->minn);
    }
    return;
}

pair<ll, ll> query(node* at, int L, int R){
    if(R < at->L || at->R < L) return {0, INF};
    if(L <= at->L && at->R <= R){
        return {at->sum, at->minn};
    }else{
        pair<ll, ll> tmp_l, tmp_r;
        tmp_l = query(at->l, L, R);
        tmp_r = query(at->r, L, R);
        return {tmp_l.fi + tmp_r.fi, min(tmp_l.se, tmp_r.se)};
    }
}

int main(){
    cin >> n;
    for(int i=0;i<n;++i){
        cin >> line[i];
    }
    node* root = build(0, n-1);
    int q;
    cin >> q;
    while(q--){
        char c;
        cin >> c;
        if(c == 'F'){
            int pos;
            cin >> pos;
            pos = translate_ind(pos);
            fen_update(pos);
            fail_point(root, pos);
            failed_ind[pos] = true;
        }else if(c == 'C'){
            int pos;
            cin >> pos;
            pos = translate_ind(pos);
            bool next_to = false;
            if(pos > 0){
                if(failed_ind[pos-1]){
                    next_to = true;
                }
            }
            if(pos < n-1){
                if(failed_ind[pos+1]){
                    next_to = true;
                }
            }
            if(next_to){
                cout << "YES\n";
            }else{
                cout << "NO\n";
            }
        }else{
            int L, R;
            cin >> L >> R;
            L = translate_ind(L);
            R = translate_ind(R);
            pair<ll, ll> ans = query(root, L, R);
            cout << ans.fi << ' ' << ans.se << endl;
        }
    }
}
