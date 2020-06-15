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

const int MAXN = 412345;

int n, m, k;
int s[MAXN];

map<int, vector<tuple<int, int, int> >> ev;

struct arv{
    int lz, tot, odd;
} tree[4*MAXN];

void build(int idx, int i, int j){
    tree[idx].odd = 0;
    tree[idx].lz = 0;
    if(i == j){
        tree[idx].tot = s[i];
        return ;
    }
    int m = (i + j)/2;
    build(idx*2, i, m);
    build(idx*2+1, m+1, j);
    tree[idx].tot = tree[idx*2].tot + tree[idx*2+1].tot;
}

void unlaze(int idx, int i, int j){
    int aux = tree[idx].lz;
    tree[idx].lz = 0;
    if(i != j && aux){
        tree[idx*2].odd = tree[idx*2].tot - tree[idx*2].odd;
        tree[idx*2].lz ^= 1;
        tree[idx*2+1].odd = tree[idx*2+1].tot - tree[idx*2+1].odd;
        tree[idx*2+1].lz ^= 1;
    }
}

void upd(int idx, int i, int j, int l, int r){
    if(i > r || j < l) return ;
    unlaze(idx, i, j);
    if(i >= l && j <= r){
        tree[idx].odd = tree[idx].tot - tree[idx].odd; 
        tree[idx].lz ^= 1;
        return ;
    }
    int m = (i + j)/2;
    upd(idx*2, i, m, l, r);
    upd(idx*2+1, m+1, j, l, r);
    tree[idx].odd = tree[idx*2].odd + tree[idx*2+1].odd;
}

int main (){
	scanf("%d", &n);
    vector<int> Y;
	for(int a=0;a<n;a++){
        int x, y, xx, yy;
        scanf("%d%d%d%d", &x, &y, &xx, &yy);
        if(x > xx)
            swap(x, xx);
        if(y > yy)
            swap(y, yy);
        if(x == xx || y == yy) continue;
        yy--;
        Y.pb(y); 
        Y.pb(yy);
        Y.pb(yy+1);
        ev[x].pb({0, y, yy});
        ev[xx].pb({1, y, yy});
	}
    sort(Y.begin(), Y.end());
    Y.erase(unique(Y.begin(), Y.end()), Y.end());
    for(int a=0;a+1<Y.size();a++){
        s[a] = Y[a+1] - Y[a];
    }
    build(1, 0, Y.size()-1);
    ll ult = 0;
    ll res = 0;
    for(auto &it: ev){
        res += (it.fst-ult)*tree[1].odd;
        ult = it.fst;
        vector<tuple<int, int, int> > &v = it.snd;
        for(int i=0;i<v.size();i++){
            int t, y, yy;     
            tie(t, y, yy) = v[i];
            y = lower_bound(Y.begin(), Y.end(), y) - Y.begin();
            yy = lower_bound(Y.begin(), Y.end(), yy) - Y.begin();
            upd(1, 0, Y.size()-1, y, yy);
        }
    }
    printf("%lld\n", res);
}
