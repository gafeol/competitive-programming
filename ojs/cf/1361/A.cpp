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

const int MAXN = 512345;

int n, m, k;
int s[MAXN];
int c[MAXN];
vector<int> adj[MAXN];

bool paint(int u, int cor){
    map<int, int> mrk;
    int cnt = 0;
    for(int nxt: adj[u]){
        if(c[nxt] > 0 && c[nxt] < cor){
            if(mrk.find(c[nxt]) == mrk.end()){
                mrk[c[nxt]] = 1;
                cnt++;
            }
        }
        if(c[nxt] == cor) return false;
    }
    c[u] = cor;
    return (cnt == cor - 1);
}

int main (){
	scanf("%d%d", &n, &m);
	for(int a=0;a<m;a++){
        int u, v;
        scanf("%d%d", &u, &v);
        adj[u].pb(v);
        adj[v].pb(u);
	}
    int ind[MAXN];
    for(int a=1;a<=n;a++){
        scanf("%d", s+a);
        ind[a] = a;
    }
    sort(ind+1, ind +n+1, [&](int a, int b) { return s[a] < s[b];});
    for(int i=1;i<=n;i++){
        int u = ind[i];
        if(!paint(u, s[u])){
            puts("-1");
            return 0;
        }
    }
    for(int i=1;i<=n;i++){
        printf("%d ", ind[i]);
    }
    puts("");
}

