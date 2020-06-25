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
#define debug(args...) fprintf(stderr,args)
#else
#define debug(args...)
#endif //ONLINE_JUDGE
template<typename T> inline T abs(T t) { return t < 0? -t : t; }
const ll modn = 1000000007;
inline ll mod(ll x) { return x % modn; }
#define IOS() ios::sync_with_stdio(0),cin.tie(0)

const int MAXN = 512345;

int n, m;
ll k;
pll s[MAXN];

map<ll, vector<pll> > pts;

ll id(pll p){
    return (p.fst - p.snd)*k + (k+(p.fst%k))%k;
}

int main (){
    for_tests(t, tt){
        pts.clear();
        scanf("%d%lld", &n, &k);
        for(int a=0;a<n;a++){
            scanf("%lld%lld", &s[a].fst, &s[a].snd);
            pts[id(s[a])].pb(s[a]);
        }
        ll dis = 0;
        for(auto it: pts){
            vector<pll> v = it.snd;
            sort(v.begin(), v.end());
            int m = v.size()/2;
            for(pll p: v){
                dis += abs((p.fst - v[m].fst)/k);
            }
        }
        printf("%d %lld\n", (int)pts.size(), dis);
    }
}

