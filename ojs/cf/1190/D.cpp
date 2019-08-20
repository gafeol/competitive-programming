#include <bits/stdc++.h>
using namespace std;
#define fst first
#define snd second
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define pb push_back
#define for_tests(t, tt) int t; scanf("%d", &t); for(int tt = 1; tt <= t; tt++)
#ifndef ONLINE_JUDGE
#define debug(args...) //fprintf(stderr,args)
#else
#define debug(args...)
#endif //ONLINE_JUDGE
template<typename T> inline T abs(T t) { return t < 0? -t : t; }
const ll modn = 1000000007;
inline ll mod(ll x) { return x % modn; }

const int MAXN = 212345;

map<ll, int> cx;
int n, m, k;

map<ll, vector<int> > p;
map<int, bool> mrk;
map<int, bool> sorted;

int bit[MAXN];

void upd(int i, int val){
    i += 2;
    while(i < MAXN){
        bit[i] += val;
        i += (i&-i);
    }
}

int qry(int i){
    i += 2;
    int ans = 0;
    while(i > 0){
        ans += bit[i];
        i -= (i&-i);
    }
    return ans;
}

int main (){
	scanf("%d", &n);
    vector<pll> s(n);
    vector<ll> X;
	for(int a=0;a<n;a++){
        ll i, j;
        scanf("%lld%lld", &i, &j);
        s[a] = {i, j};
        X.pb(i);
	}
    sort(X.begin(), X.end());
    X.erase(unique(X.begin(), X.end()), X.end());
    for(int i=0;i<X.size();i++)
        cx[X[i]] = i;
    for(int a=0;a<n;a++){
        p[s[a].snd].pb(cx[s[a].fst]);
    }
    for(int a=0;a<n;a++){
        if(sorted[s[a].snd]) continue;
        sorted[s[a].snd] = true;
        sort(p[s[a].snd].begin(), p[s[a].snd].end());
    }
    int sz = 0;
    ll res = 0;
    for(auto it=p.rbegin();it != p.rend();it++){
        int y = it->fst;
        debug("y %d\n", y);
        vector<int> points = it->snd;
        ll nsz = sz + points.size();
        for(int x: points){
            if(mrk[x]){
                nsz--;
                upd(x, -1);
            }
        }
        res += nsz*nsz;
        debug("res += %lld\n", nsz*nsz);
        ll jafoi = 0; 
        for(int x: points){
            ll bef = qry(x);
            res -= (bef + 1 - jafoi)*bef;
            debug("res -= %lld*%lld\n", bef+1-jafoi,bef);
            jafoi = bef+1;
            mrk[x] = true;
            upd(x, 1);
        }
        res -= (nsz - jafoi)*nsz;
        debug("res -= %lld*%lld\n", nsz-jafoi,nsz);
        sz = nsz;
    }
    printf("%lld\n", res);
}

