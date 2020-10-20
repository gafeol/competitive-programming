#include "bits/stdc++.h"
using namespace std;
#define fst first
#define snd second
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
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
#define IOS() ios::sync_with_stdio(0),cin.tie(0)

const int MAXN = 212345;

int n, m, k;
ll s[MAXN];
int p[MAXN];

set<pli> q;

ll sq(ll x){
    return x*x;
}

ll cus(ll x, int pt){
    ll res = x%pt;
    ll div = x/pt;
    return res*sq(div+1) + (pt - res)*sq(div);
}

void add(int i){
    if(p[i] == s[i]) return;
    ll act = cus(s[i], p[i]);
    ll aft = cus(s[i], p[i]+1);
    debug("add i %d cus %lld com p %d proxcus %lld\n", i, act, p[i], aft);
    q.insert({aft - act, i});
}

int main (){
	scanf("%d%d", &n, &k);
    ll res = 0;
	for(int a=0;a<n;a++){
        scanf("%lld", s+a);
        p[a] = 1;
        add(a);
        res += cus(s[a], 1);
	}
    debug("res %lld\n", res);
    while(k > n){
        k--;
        auto bg = *q.begin();        
        debug("pega %lld %d\n", bg.fst, bg.snd);
        res += bg.fst;
        q.erase(q.begin());
        p[bg.snd]++;
        add(bg.snd);
    }
    printf("%lld\n", res);
}

