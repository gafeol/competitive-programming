#include <bits/stdc++.h>
using namespace std;
#define fst first
#define snd second
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
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
pll s[MAXN];
ll v[MAXN];
int ind[MAXN];

int main (){
    scanf("%d%d", &n, &m);
    map<ll, vector<pli>> ev;
    for(int a=0;a<n;a++){
        ll l, r;
        scanf("%lld %lld", &l, &r);
        s[a] = {l, r};
        if(a > 0)
            ev[l - s[a-1].snd].pb({r - s[a-1].fst, a-1});
    }
    for(int a=0;a<m;a++){
        ind[a] = a;
        scanf("%lld", v+a);
    }
    sort(ind, ind+m, [](int a, int b) { return v[a] < v[b]; });
    auto it = ev.begin();
    set<pli> q;
    bool ok = true;
    int ans[MAXN];
    for(int aa=0;aa<m;aa++){
        int a = ind[aa];
        debug("analisa a %d sz %lld\n", a, v[a]);
        while(it != ev.end() && it->fst <= v[a]){
            for(pli p: it->snd){
                debug("insere %lld %d\n", p.fst, p.snd);
                q.insert(p);
            }
            it++;
        }
        if(!q.empty()){
            pli top = *q.begin(); 
            q.erase(q.begin());
            if(top.fst < v[a]){
                ok = false;
                break;
            }
            ans[top.snd] = a+1;
        }
    }
    if(it != ev.end() || !q.empty())
        ok = false;
    if(ok){
        puts("Yes");
        for(int a=0;a<n-1;a++){
            printf("%d ", ans[a]);
        }
        puts("");
    }
    else
        puts("No");
}

