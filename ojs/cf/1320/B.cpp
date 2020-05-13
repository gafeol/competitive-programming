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

const int INF = 0x3f3f3f3f;
const int MAXN = 212345;

int n, m, k;
int s[MAXN];

vector<int> adj[MAXN], inv[MAXN];
int d[MAXN];

int cnt[MAXN];

void dij(int u){
    set<pii> q;
    memset(d, INF, sizeof(d));
    d[u] = 0;
    q.insert({d[u], u});
    while(!q.empty()){
        int u = q.begin()->snd; 
        q.erase(q.begin());
        for(int nxt: inv[u]){
            if(d[nxt] > d[u] + 1){
                if(d[nxt] != INF)
                    q.erase({d[nxt],nxt});
                d[nxt] = d[u] + 1;
                q.insert({d[nxt], nxt});
            }
        }
    }
}

int main (){
	scanf("%d%d", &n, &m);
	for(int a=0;a<m;a++){
        int i, j;
        scanf("%d%d", &i, &j);
        adj[i].pb(j);
        inv[j].pb(i);
	}
    scanf("%d", &k);
    for(int a=0;a<k;a++){
        scanf("%d", s+a);
    }
    dij(s[k-1]);
    for(int a=1;a<=n;a++){
        for(int nxt: adj[a]){
            if(d[nxt] == d[a] - 1)
                cnt[a]++;
        }
    }
    int mn=0, mx=0;
    for(int a=1;a<k;a++){
        int u = s[a-1];
        int nxt = s[a];
        if(d[u]-1 == d[nxt]){
            if(cnt[u] > 1)
                mx++;
        }
        else{
            mn++;
            mx++;
        }
    }
    printf("%d %d\n", mn, mx);
}

