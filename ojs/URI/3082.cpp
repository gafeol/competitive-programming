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
int ans[MAXN];
int sz[MAXN];
vector<int> adj[MAXN];

int mrk[MAXN];

int getsz(int u, int p){
    sz[u] = 1;
    for(int nxt: adj[u]){
        if(nxt == p || mrk[nxt]) continue;
        sz[u] += getsz(nxt, u);
    }
    return sz[u];
}

int getc(int u, int p, int tot){
    for(int nxt: adj[u]){
        if(nxt == p || mrk[nxt]) continue;
        if(sz[nxt]*2 >= tot)
           return getc(nxt, u, tot);
    }
    return u;
}


vector<int> sumDis;
void getSum(int u, int p, int d=0){
    if(sumDis.size() <= d)
        sumDis.resize(d+1);
    sumDis[d]++;
    for(int nxt: adj[u]){
        if(mrk[nxt] || nxt == p) continue;
        getSum(nxt, u, d+1);
    }
}

void updAns(int u, int p, int d=0, int t=1){
    if(d > k) return ;
    ans[u] += t*sumDis[min(k-d, (int)sumDis.size()-1)];
    for(int nxt: adj[u]){
        if(mrk[nxt] || nxt == p) continue;
        updAns(nxt, u, d+1, t);
    }
}
void go(int u){
    int sz = getsz(u, u);
    int c = getc(u, u, sz);
    //printf("go %d sz %d c %d\n", u, sz, c);
    sumDis.clear();
    getSum(c, c);
    for(int a=1;a<sumDis.size();a++) sumDis[a] += sumDis[a-1];
    updAns(c, c);

    mrk[c] = 1;
    for(int nxt: adj[c]){
        if(mrk[nxt]) continue;
        sumDis.clear(); 
        getSum(nxt, nxt);
        for(int a=1;a<sumDis.size();a++) sumDis[a] += sumDis[a-1];
        updAns(nxt, nxt, 2, -1);
    }
    for(int nxt: adj[c]){
        if(mrk[nxt]) continue;
        go(nxt);
    }
}

int main (){
	scanf("%d%d", &n, &k);
	for(int a=1;a<n;a++){
        int i, j;
        scanf("%d%d", &i, &j);
        adj[i].pb(j);
        adj[j].pb(i);
	}
    go(1);
    for(int a=1;a<=n;a++){
        printf("%d\n", ans[a]);
    }
}

