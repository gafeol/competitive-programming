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

const int MAXN = 312345;

int n, m, k;
int s[MAXN];

vector<vector<int>> bt;

vector<int> over;

int state[MAXN];
bool ok;
int ans;
vector<int> vis;

void go(int u, int t){
    if(!ok) return;
    if(state[u] != -1){
        if(state[u] != t)
            ok = false;
        return;
    }

    state[u] = t;
    ans += t;
    vis.pb(u);
    for(int i: bt[u]){
        bool exp = (s[a]^t);
        int cnt = 0;
        assert(over[i].size() <= 2);
        if(over[i].size() == 1 && s[i] == t){
            ok = false;
            return ;
        }
        for(int ot: over[i]){
            if(ot == u) continue;
            go(ot, exp);
        }
    }
}

int main (){
	scanf("%d%d", &n, &m);
	for(int a=0;a<n;a++){
        char c;
        scanf(" %c", &c);
        s[a] = c-'0';
	}
    for(int a=0;a<m;a++){
        scanf("%d", &q);
        vector<int> chg;
        while(q--){
            int x;
            scanf("%d", &x); 
            x--;
            chg.pb(x);
            over[x].pb(a);
        }
        bt.pb(chg);
    }
    int res = 0;
    memset(state, -1, sizeof(state));
    ans = 0;
    for(int a=0;a<m;a++){
        bool ok0, ok1;
        ok0 = ok1 = false;
        int ans0, ans1;
        ans0 = ans1 = 0;
        if(state[a] == -1){
            vis.clear();
            ok = true;
            ans = 0;
            go(a, 0);
            ok0 = ok;
            ans0 = ans;
            for(int u: vis){
                state[u] = -1;
            }
            vis.clear();
            ok = true;
            ans = 0;
            go(a, 1);
            ok1 = ok;
            ans1 = ans;


            for(int u: vis)
                state[u] = -1;
            vis.clear();
            ok = true;
            ans = 0;
            if(ok0 && ok1){
                if(ans0 < ans1){
                    go();
                }
            }
        }
    }
}

