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
ll deg[MAXN];

int main (){
	scanf("%d%d", &n, &m);
	for(int a=0;a<m;a++){
        int i, j;
        ll x;
        scanf("%d%d%lld", &i, &j, &x);
        deg[i] += x;
        deg[j] -= x;
	}
    vector<int> v[2];
    for(int a=1;a<=n;a++){
        if(deg[a] > 0){
            v[0].pb(a);
        }
        else if(deg[a] < 0)
            v[1].pb(a);
    }
    int i = 0, j = 0;
    vector<tuple<int, int, ll> > ans;
    while(i < v[0].size()){
        int u = v[0][i];
        while(deg[u] > 0){
            int uu = v[1][j];
            ll mn = min(deg[u], abs(deg[uu]));
            if(mn > 0)
                ans.pb({u, uu, mn});
            deg[u] -= mn;
            deg[uu] += mn;
            if(deg[uu] == 0)
                j++;
        }
        i++;
    }
    printf("%d\n", (int)ans.size());
    for(int a=0;a<ans.size();a++){
        int i, j;
        ll x;
        tie(i, j, x) = ans[a];
        printf("%d %d %lld\n", i,j, x);
    }
}

