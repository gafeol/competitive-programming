#include <bits/stdc++.h>
using namespace std;
#define fst first
#define snd second
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;
#define pb push_back
#define for_tests(t, tt) int t; scanf("%d", &t); for(int tt = 1; tt <= t; tt++)
#ifndef ONLINE_JUDGE
#define debug(args...) fprintf(stderr,args)
#else
#define debug(args...)
#endif //ONLINE_JUDGE
template<typename T> inline T abs(T t) { return t < 0? -t : t; }
const ll modn = 1000000007;
inline ll mod(ll x) { return x % modn; }
#define IOS() ios::sync_with_stdio(0),cin.tie(0)

const int MAXN = 212345;

int n, m, k;
int s[MAXN], sp[MAXN];
vector<int> adj[MAXN];

int getsz(int u, int p){
    for(int nxt: adj[u]){
        if(nxt == p) continue;
        s[u] += getsz(nxt, u);
    }
    return s[u];
}

int getc(int u, int p, int tot){
    for(int nxt: adj[u]){
        if(nxt == p) continue;
        if(s[nxt]*2 > tot){
            return getc(nxt, u, tot);
        }
    }
    return u;
}

void go(int u, int p, vector<int> &q){
    if(sp[u])
        q.pb(u);
    for(int nxt: adj[u]){
        if(nxt == p) continue;
        go(nxt, u, q);
    }
}

struct sz_cmp {
    bool operator() (const vector<int>& a, vector<int>& b) const {
        return a.size() > b.size();
    }
};

int main (){
	scanf("%d%d", &n, &k);
	for(int a=1;a<n;a++){
        int i, j;
        scanf("%d%d", &i, &j);
        adj[i].pb(j);
        adj[j].pb(i);
	}
    for(int a=0;a<2*k;a++){
        int x;
        scanf("%d", &x);
        sp[x] = s[x] = 1;
    }
    getsz(1, 1);
    int c = getc(1, 1, s[1]);
    printf("1\n%d\n", c);
    vector<vector<int>> vv;
    set<pii, greater<pii>> v;
    for(int nxt: adj[c]){
        vector<int> q; 
        go(nxt, c, q);
        if(!q.empty()){
            v.insert({q.size(), vv.size()});
            vv.pb(q);
        }
    }
    if(sp[c]){
        v.insert({1, vv.size()});
        vv.pb(vector<int>(1, c));
    }

    vector<pii> ans;
    while(!v.empty()){
        pii pa = *v.begin();
        int a = pa.snd;
        v.erase(v.begin());
        pii pb = *v.begin();
        int b = pb.snd;
        v.erase(v.begin());
        ans.pb({vv[a].back(), vv[b].back()});
        vv[a].pop_back();
        vv[b].pop_back();
        if(!vv[a].empty())
            v.insert({vv[a].size(), a});
        if(!vv[b].empty())
            v.insert({vv[b].size(), b});
    }
    for(pii p : ans){
        printf("%d %d %d\n", p.fst, p.snd, c);
    }
}

