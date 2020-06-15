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

const int MAXN = 212345;
const int INF = 0x3f3f3f3f;

int n, m, k;
int d[MAXN];
int sp[MAXN];

vector<int> adj[MAXN];
int main (){
	scanf("%d%d", &n, &m);
	for(int a=1;a<n;a++){
        int i, j;
        scanf("%d%d", &i, &j);
        adj[i].pb(j);
        adj[j].pb(i);
	}
    queue<int> q;
    memset(d, INF, sizeof(d));
    for(int a=0;a<m;a++){
        int x;
        scanf("%d", &x);
        sp[x] = 1;
        d[x] = 0;
        q.push(x);
    }
    while(!q.empty()){
        int u = q.front();
        q.pop();
        for(int nxt: adj[u]){
            if(d[nxt] == INF){
                d[nxt] = d[u] + 1; 
                q.push(nxt);
            }
            if(d[nxt] == d[u] + 1)
                sp[nxt] += sp[u];
        }
    }
    for(int a=1;a<=n;a++){
        if(sp[a] == m){
            puts("YES");
            printf("%d\n", a);
            return 0;
        }
    }
    puts("NO");
}

