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

int n, m, k, a, b;
int s[MAXN], mrk[MAXN];

bool ha, hb;
int cnt;
vector<int> adj[MAXN];

void go(int u){
    mrk[u] = 1;
    cnt++;
    for(int nxt: adj[u]){
        ha |= (nxt == a);
        hb |= (nxt == b);
        if(mrk[nxt]) continue;
        go(nxt);
    }
}

int main (){
    for_tests(t, tt){
        scanf("%d%d%d%d", &n, &m, &a, &b);
        for(int a=0;a<=n;a++){
            mrk[a] = 0;
            adj[a].clear();
        }
        for(int a=0;a<m;a++){
            int i, j;
            scanf("%d%d", &i, &j);
            adj[i].pb(j);
            adj[j].pb(i);
        }
        mrk[a] = 1;
        mrk[b] = 1;
        int ra = 0, rb = 0;
        for(int nxt: adj[a]){
            ha = false;
            hb = false;
            cnt = 0;
            if(!mrk[nxt])
                go(nxt);
            if(!hb){
                ra += cnt; 
            }
        }
        for(int nxt: adj[b]){
            ha = false;
            hb = false;
            cnt = 0;
            if(!mrk[nxt])
                go(nxt);
            if(!ha)
                rb += cnt; 
        }
        ll res = ((ll)ra)*rb;
        printf("%lld\n", res);
    }
}

