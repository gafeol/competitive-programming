#include <bits/stdc++.h>
using namespace std;
#define fst first
#define snd second
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
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

const int MAXN = 3123;
int n, m, k;
int s[MAXN];

ll ch(ll x){
    return x*(x-1)/2ll;
}

vector<ll> getCoins(vector<pii> ln){
    unordered_map<int, vector<int>>  slp;
    ll paresParal = 0;
    ll tot = ln.size();
    slp.clear();
    for(pii p:ln){
        paresParal += slp[p.fst].size();
        slp[p.fst].pb(p.snd);
    }
    vector<ll> ans; 
    while(tot){
        int mx;
        ll mxVal = LLONG_MIN;
        for(auto it: slp){
            ll val = ch(tot - it.snd.size()) - paresParal + ch(it.snd.size());
            if(mxVal < val){
                mxVal = val;
                mx = it.fst;
            }
        }
        ans.pb(mxVal);
        slp[mx].pop_back();
        paresParal -= slp[mx].size();
        if(slp[mx].empty())
            slp.erase(mx);
        tot--;
    }
    return ans;
}

ll getInter(vector<pii> ln){
    unordered_map<int, vector<int>>  slp;
    ll paresParal = 0;
    for(pii p:ln){
        paresParal += slp[p.fst].size();
        slp[p.fst].pb(p.snd);
    }

    ll tot = ln.size();
    ll ans = 0;
    for(auto it: slp){
        ll val = ((ll)it.snd.size())*(ch(tot - it.snd.size()) - paresParal + ch(it.snd.size()));
        ans += val;
    }
    return ans/3ll;
}

int main (){
    for_tests(t, tt){
        scanf("%d%d%d", &n, &m, &k);
        vector<vector<pii>> ln(m);
        for(int a=0;a<n;a++){
            int x, y, z;
            scanf("%d%d%d", &x, &y, &z);
            z--;
            ln[z].pb({x, y});
        }
        ll tot = 0;
        for(int a=0;a<m;a++){
            tot += getInter(ln[a]);
            //printf("cor %d inter %lld\n", a, getInter(ln[a]));
        }
        for(int a=0;a<m;a++)
            scanf("%d", s+a);
        vector<pli> moedas;
        for(int a=0;a<m;a++){
            vector<ll> val = getCoins(ln[a]);
            for(ll x: val){
                moedas.pb({x, s[a]});
            }
        }
        vector<ll> dp(k+1, LLONG_MAX);
        dp[k] = tot;
        ll res = tot;
        for(pli p: moedas){
            ll disc = p.fst;
            int pes = p.snd;
            for(int val=pes;val<=k;val++){
                if(dp[val] == LLONG_MAX) continue; 
                dp[val-pes] = min(dp[val-pes], dp[val] - disc);
                res = min(res, dp[val-pes]);
            }
        }
        printf("%lld\n", res);
    }
}
