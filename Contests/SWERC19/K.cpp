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

int n, m, k;
int s[MAXN];

int cnt[MAXN];
int mrk[MAXN];
int tempo;

vector<int> sp;
vector<int> inv[MAXN];

void go(int u){
    if(mrk[u] == tempo || cnt[u] >= 2) return;
    mrk[u] = tempo;
    cnt[u]++;
    for(int nxt: inv[u])
        go(nxt);
}

int main (){
	scanf("%d%d%d", &n, &m, &k);
	for(int a=0;a<m;a++){
        int i, j;
        scanf("%d %d", &i, &j); 
        if(i == k) continue;
        if(j == k)
            sp.pb(i);
        else
            inv[j].pb(i);
	}
    for(int u: sp){
        tempo++;
        go(u);
    }
    vector<int> ans;
    for(int x: sp)
        if(cnt[x] == 1)
            ans.pb(x);
    sort(ans.begin(), ans.end());
    printf("%d\n", ans.size());
    for(int x: ans)
        printf("%d\n", x);
}

