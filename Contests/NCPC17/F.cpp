#include <bits/stdc++.h>
using namespace std;
#define fst first
#define snd second
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;
#define pb push_back
#define for_tests(t, tt) int t; scanf("%d", &t); for(int tt = 1; tt <= t; tt++)

template <typename T> void write(ostream& out, T t) {
	out << t << "\n";
}
template <typename T, typename... Args>
void write(ostream& out, T t, Args... args) {
	out << t << ' ';
	write(out, args...);
}

template <typename... Args>
void debug(Args... args) {
	#ifdef LOCAL
		write(cerr, args...);
	#endif
}


template<typename T> inline T abs(T t) { return t < 0? -t : t; }
const ll modn = 1000000007;
inline ll mod(ll x) { return x % modn; }

const int MAXN = 212345, LOGN = 22;

int n, m, k;
int s[MAXN];

void prep_cin(){
	ios::sync_with_stdio(false);
	cin.tie(0);
}

vector<int> adj[MAXN];
vector<pair<ll, int> > f[MAXN];
ll sz[MAXN];

ll prof[MAXN];

int dfs(int u, int h){
    if(adj[u].empty())
        return h;
 return dfs(adj[u][0], h+1);
}

int pai[MAXN][LOGN];
void dfs2(int u, int h=0){
   for(int a=1;a<LOGN;a++)
        pai[u][a] = pai[pai[u][a-1]][a-1];
    prof[u]= h;
    for(int nxt: adj[u])
        dfs2(nxt, h+1);
}

ll go(int u, int k, ll t){
    ll tam = (k == 0 ? 1 : sz[k-1]);
    if(!adj[u].empty()){
        f[k].pb({t++, u}); 
        for(int nxt: adj[u]){
            t = go(nxt, k, t);
        }
        return t;
    }
    else{
        f[k].pb({t, u}); 
        return t+tam;
    }
}

ll depth(ll u, int k){
    auto it = --upper_bound(f[k].begin(), f[k].end(), make_pair(u, INT_MAX));
    auto i = it->snd;
    if(k == 0){
        return prof[i];
    }

    if(adj[i].empty()){
        //printf("i %d u %lld it->fst %lld\n", i, u, it->fst);
        return depth(u - it->fst, k-1) + prof[i];
    }
    return prof[i];
}

int find_lca(int i, int j){
    if(prof[i] < prof[j])
        swap(i, j);
        

    if(i == j) return i;

    if(prof[i] != prof[j]){
        for(int a=LOGN-1;a>=0;a--){
            if(prof[pai[i][a]] > prof[j])
                i = pai[i][a];
        }
        i= pai[i][0];
    }
    if(i == j) return i;
    
    for(int a=LOGN-1;a>=0;a--){
        if(pai[i][a] != pai[j][a]){
            i = pai[i][a];
            j= pai[j][a];
        }
    }
    return pai[i][0];
}

ll solve(ll a, ll b, int k){
    auto ia = --upper_bound(f[k].begin(), f[k].end(), make_pair(a, INT_MAX));
    auto ib = --upper_bound(f[k].begin(), f[k].end(), make_pair(b, INT_MAX));
    if(!k){
        int lca = find_lca(ia->snd, ib->snd);
        return prof[ia->snd] + prof[ib->snd] - 2ll*prof[lca];
    }

    
    if(ia == ib) 
        return solve(a-ia->fst, b-ia->fst, k-1);

    int lca = find_lca(ia->snd, ib->snd);
    return depth(a-ia->fst, k-1) + depth(b-ib->fst, k-1) + prof[ib->snd] + prof[ia->snd] - 2ll*prof[lca];
}

int main (){
	scanf("%d", &n);
	for(int a=1;a<n;a++){
        int p;
        scanf("%d", &p);
        adj[p].pb(a);
        pai[a][0] = p;
	}
    ll nf = 0;
    for(int a=0;a<n;a++){
        if(adj[a].empty()){ 
            nf++;
            continue;
        }
        sort(adj[a].begin(), adj[a].end());
    }
    dfs2(0);

    if(nf == 1){
        scanf("%d", &k);
        int q;
        scanf("%d", &q);
        for(int a=0;a<q;a++){
            ll i, j;
            scanf("%lld%lld",&i, &j); 
            i--;j--;
                printf("%lld\n", abs(i-j));
        }
        return 0;

    }
    ll r= 0;
    scanf("%d", &k);

    sz[0] = n;
    int kk;

    for(ll a=1, f = 1;;a++){
        sz[a] = sz[a-1] + (ll)(n-1ll)*f*nf;
        f *= nf;
        if(sz[a] > (1<<30)){
            kk = a;
            break;
        }
    }
    if(k > kk) {
        int d = dfs(0, 0);
        r = k-kk - (k-kk)%d;
        k = kk; 
    }
    printf("r %lld\n", r);
    for(int a=0;a<=k;a++)
        go(0, a, 0ll);

    int q;
    scanf("%d", &q);
    for(int a=0;a<q;a++){
        ll i, j;
        scanf("%lld%lld",&i, &j); 
        i--;j--;
        if(max(i, j) <= r){
            printf("%lld\n", abs(i-j));
        }
        else if(min(i, j) <= r){
            if(i > j) swap(i, j);
            printf("%lld %lld %lld \n", j-r, sz[k-1], sz[k]);
            printf("%lld\n", depth(j-r, k) + r - i);
        }
        else
            printf("%lld\n", solve(i-r, j-r, k));
    }
}
