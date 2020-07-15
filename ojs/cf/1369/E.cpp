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
pii s[MAXN];
int qtd[MAXN], saldo[MAXN];
int mrkf[MAXN], mrkp[MAXN];

vector<int> has[MAXN];

int main (){
	scanf("%d%d", &n, &m);
	for(int a=1;a<=n;a++){
        scanf("%d", qtd+a);
        saldo[a] = qtd[a];
        has[a].clear();
	}
    for(int a=0;a<m;a++){
        scanf("%d%d", &s[a].fst, &s[a].snd);
        has[s[a].fst].pb(a);
        has[s[a].snd].pb(a);
        saldo[s[a].fst]--;
        saldo[s[a].snd]--;
    }
    set<pii> q;
    for(int a=1;a<=n;a++)
        q.insert({-saldo[a], a});
    stack<int> ans;
    while(!q.empty()){
        pii p = *q.begin();
        q.erase(q.begin()); 
        int i = p.snd;
        mrkf[i] = true;
        //printf("i %d saldo %d\n", i, saldo[i]);
        if(saldo[i] < 0){
            puts("DEAD");
            return 0;
        }
        for(int u: has[i]){
            if(mrkp[u]) continue;
            ans.push(u);
            mrkp[u] = 1;
            if(!mrkf[s[u].fst]){
                q.erase({-saldo[s[u].fst], s[u].fst});
                saldo[s[u].fst]++;
                q.insert({-saldo[s[u].fst], s[u].fst});
            }
            if(!mrkf[s[u].snd]){
                q.erase({-saldo[s[u].snd], s[u].snd});
                saldo[s[u].snd]++;
                q.insert({-saldo[s[u].snd], s[u].snd});

            }
        }
    }
    puts("ALIVE");
    while(!ans.empty()){
        printf("%d ", 1+ans.top());
        ans.pop();
    }
    puts("");
}

