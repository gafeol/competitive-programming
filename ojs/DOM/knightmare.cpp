#include <bits/stdc++.h>
using namespace std;
#define fst first
#define snd second
#define mp make_pair
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

int n, m, k;

map<ll, vector<pair<pair<ll, ll>, ll>>> ev;
map<ll, int> acc;

void add(ll i, ll j, ll ii, ll jj){
    if(i < 0) return;
    if(jj < 0) return;
    if(i < ii || j < jj) return;
    ii = max(ii, 0ll);
    j = max(j, 0ll);
    if(i < ii || j < jj) return;
    ev[jj].pb(mp(mp(0ll, ii), i)); 
    ev[j+1].pb(mp(mp(1ll, ii), i));
    acc[ii] = 0;
    acc[i+1] = 0;
}

int main (){
    for_tests(t, tt){
        ev.clear();
        acc.clear();
        scanf("%d%d", &n, &k);
        for(int a=0;a<n;a++){
            ll i, j, l, r;
            scanf("%lld%lld%lld%lld", &i, &j, &l, &r);
            if(l < r)
                swap(l, r);
            add(i+r, j-l, i+1, j-r-1);
            add(i+l, j-r, i+1, j-1);
            add(i+l, j+1, i+1, j+r);
            add(i+r, j+r+1, i+1, j+l);
            add(i-1, j+r+1, i-r, j+l);
            add(i-1, j+1, i-l, j+r);
            add(i-1, j-r, i-l, j-1);
            add(i-1, j-l, i-r, j-r-1);
        }
        ll lx = 0;
        ll cnt = 0;
        ll ans = 0;
        for(auto it: ev){
            //printf("de x %d ate %d tem cnt %d\n", lx, it.fst, cnt);
            assert(it.fst >= 0);
            assert(cnt >= 0);
            ans += cnt*(it.fst - lx);
            lx = it.fst;
            //printf("it x %d\n", it.fst);
            vector<pair<pair<ll, ll>, ll>> &v = it.snd;
            for(pair<pair<ll, ll>, ll> tp: v){
                ll t, l, r;
                t = tp.fst.fst;
                l = tp.fst.snd;
                r = tp.snd;
                auto it = acc.find(l);
                auto fim = acc.find(r+1);
                assert(it != acc.end());
                assert(fim != acc.end());
                if(!t){
                    ll ly = l;
                    ll lstval = 0;
                    while(it != fim){
                        it->snd++; 
                        assert(it->fst >= ly);
                        if(lstval == k)
                            cnt += it->fst - ly;
                        lstval = it->snd;
                        ly = it->fst;
                        it++;
                    }
                    if(lstval == k)
                        cnt += fim->fst - ly;
                }
                else{
                    ll ly = l;
                    ll lstval = -1;
                    while(it != fim){
                        it->snd--; 
                        assert(it->fst >= ly);
                        if(lstval == k-1)
                            cnt -= it->fst - ly;
                        lstval = it->snd;
                        assert(lstval >= 0);
                        ly = it->fst;
                        it++;
                    }
                    if(lstval == k-1)
                        cnt -= fim->fst - ly;
                }
            }
        }
        printf("%lld\n", ans);
    }
}

