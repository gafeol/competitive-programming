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

int n;
vector<int> adj[MAXN];
int d[MAXN], prv[MAXN];
int cyc;

void go(int u){
    queue<int> q;
    for(int a=0;a<n;a++)
        d[a] = -1;
    d[u] = 0;
    q.push(u);
    while(!q.empty()){
        u = q.front();
        q.pop();
        for(int nxt: adj[u]){
            if(d[nxt] != -1){
                if(prv[u] != nxt)
                    cyc = min(cyc, 1 + d[u] + d[nxt]);
                continue;
            }
            d[nxt] = d[u] + 1;
            prv[nxt] = u;
            q.push(nxt);
        }
    }
}

int main (){
	scanf("%d", &n);
    vector<ll> s;
	for(int a=0;a<n;a++){
        ll x;
        scanf("%lld", &x);
        if(x > 0)
            s.pb(x);
	}
    n = s.size();
    if(n > 130){
        puts("3");
        return 0;
    }
    for(int a=0;a<n;a++){
        for(int b=a+1;b<n;b++){
            if((s[a]&s[b]) > 0){
                adj[a].pb(b);
                adj[b].pb(a);
            }
        }
    }
    cyc = INT_MAX;
    for(int u=0;u<n;u++){
        go(u);
    }
    if(cyc == INT_MAX)
        puts("-1");
    else
        printf("%d\n", cyc);
}

