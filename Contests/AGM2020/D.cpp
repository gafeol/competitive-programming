#include <bits/stdc++.h>
using namespace std;
#define fst first
#define snd second
typedef unsigned long long ull;
typedef long long ll;
typedef pair<ll, ll> pll;
#define pb push_back
#define for_tests(t, tt) int t; scanf("%d", &t); for(int tt = 1; tt <= t; tt++)
#ifndef ONLINE_JUDGE
#define debug(args...) fprintf(stderr,args)
#else
#define debug(args...)
#endif //ONLINE_JUDGE
template<typename T> inline T abs(T t) { return t < 0? -t : t; }
const ll modn = 1000000007;
const ll modn2 = 1000000009;
inline ll mod(ll x) { return x % modn; }
inline ll mod2(ll x) { return x % modn2; }
#define IOS() ios::sync_with_stdio(0),cin.tie(0)

const int MAXN = 32;

int np, nc, k;
int s[2][MAXN][MAXN];
int b[MAXN];

//map<map<int, int>, int> mrk;
map<pll, int> mrk;

pll hx(vector<int> &v){
    ll h = 0;
    ll h2 = 0;
    for(int i=0;i<v.size();i++){
        h = mod(h*2003);
        h = mod(h + v[i]);
        h2 = mod2(h*2011);
        h2 = mod2(h2 + v[i]);
    }
    return {h, h2};
}

int main (){
    for_tests(t, tt){
        mrk.clear();
        scanf("%d%d", &np, &nc);
        for(int a=0;a<nc;a++){
            scanf("%d", b+a);
        }
        for(int a=0;a<np;a++){
            for(int b=0;b<nc;b++){
                for(int t=0;t<2;t++){
                    scanf("%d", &s[t][a][b]);
                }
            }
        }
        int mid = np/2;
        for(int bm=0;bm<(1<<mid);bm++){
            vector<int> cnt(nc, 0);
            int cus = 0;
            for(int p=0;p<mid;p++){
                int t = ((bm&(1<<p)) > 0);
                cus += t;
                for(int u=0;u<nc;u++){
                    cnt[u] += s[t][p][u];
                }
            }
            bool ok = true;
            for(int u=0;u<nc;u++)
                if(cnt[u] > b[u])
                    ok = false;
            if(!ok) continue;
            pll h = hx(cnt);
            if(mrk.find(h) != mrk.end())
                mrk[h] = min(mrk[h], cus);
            else
                mrk[h] = cus;
        }

        int ans = INT_MAX;
        for(int bm=0;bm<(1<<(np-mid));bm++){
            vector<int> cnt(nc, 0);
            for(int u=0;u<nc;u++)
                cnt[u] = 0;
            int cus = 0;
            for(int p=mid;p<np;p++){
                int t = ((bm&(1<<(p-mid))) > 0);
                cus += t;
                for(int u=0;u<nc;u++)
                    cnt[u] += s[t][p][u];
            }
            bool ok = true;
            for(int u=0;u<nc;u++)
                if(cnt[u] > b[u])
                    ok = false;
            if(!ok) continue;
            for(int u=0;u<nc;u++){
                cnt[u] = b[u] - cnt[u];
            }
            pll h = hx(cnt);
            if(mrk.find(h) != mrk.end())
                ans = min(ans, cus + mrk[h]);
        }
        if(ans < INT_MAX)
            printf("%d\n", ans);
        else
            puts("impossible");
    }
}
