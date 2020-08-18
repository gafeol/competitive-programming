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
int s[MAXN];
bool mrk[MAXN];
ll fom[MAXN], fru[MAXN];

vector<int> adj[MAXN];
vector<int> fil[MAXN];

int p[MAXN];
int sz[MAXN];
int top[MAXN];
int ans[MAXN];
int dia[MAXN];

vector<ll> acc;
vector<int> d;

void go(int u){
    ll prv = (acc.empty() ? 0 : acc.back());
    acc.pb(prv + fom[u]);
    d.pb(dia[u]);

    if(acc.back() < fru[u])
        ans[u] = -1;
    else
        ans[u] = d[lower_bound(acc.begin(), acc.end(), fru[u]) - acc.begin()];

    for(int nxt: fil[u])
        go(nxt);

    acc.pop_back();
    d.pop_back();
}

int raiz(int u){
    if(p[u] == u) return u;
    return p[u] = raiz(p[u]);
}
void join(int i, int j){
    i = raiz(i);
    j = raiz(j);
    assert(i != j);
    if(sz[i] < sz[j]) swap(i, j);
    p[j] = i;
    sz[i] += sz[j];
}

int main (){
    for_tests(t, tt){
        scanf("%d", &n);
        for(int a=0;a<n;a++){
            mrk[a] = false;
            adj[a].clear();
            fil[a].clear();
            p[a] = a;
            sz[a] = 1;
            ans[a] = -1;
        }
        for(int a=1;a<n;a++){
            int i, j;
            scanf("%d%d", &i, &j);
            i--;j--;
            adj[i].pb(j);
            adj[j].pb(i);
        }
        for(int a=0;a<n;a++){
            scanf("%d", s+a);
            s[a]--;
            dia[s[a]] = a+1;
        }
        for(int a=n-1;a>=0;a--){
            int u = s[a];
            mrk[u] = true;
            for(int nxt: adj[u]){
                if(mrk[nxt]){
                    fil[u].pb(top[raiz(nxt)]);
                    join(u, nxt);
                }
            }
            top[raiz(u)] = u;
        }
        for(int a=0;a<n;a++)
            scanf("%lld", fom+a);
        for(int a=0;a<n;a++)
            scanf("%lld", fru+a);
        go(s[0]);
        for(int a=0;a<n;a++){
            printf("%d ", ans[a]);
        }
        puts("");
    }
}

