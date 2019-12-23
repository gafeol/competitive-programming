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

map<int, vector<pair<pair<bool, int>, int>>> ev;
map<int, short> acc;
vector<int> pos;

void add(int i, int j, int ii, int jj){
    if(i < 0) return;
    if(jj < 0) return;
    if(i < ii || j > jj) return;
    ii = max(ii, 0);
    j = max(j, 0);
    ev[j].pb(mp(mp(0, ii), i)); 
    ev[jj+1].pb(mp(mp(1, ii), i));
    if(acc.find(ii) == acc.end()){
        pos.pb(ii);
        acc[ii] = 0;
    }
    if(acc.find(i+1) == acc.end()){
        pos.pb(i+1);
        acc[i+1] = 0;
    }
}

int main (){
    for_tests(t, tt){
        ev.clear();
        acc.clear();
        scanf("%d%d", &n, &k);
        for(int a=0;a<n;a++){
            int i, j, l, r;
            scanf("%d%d%d%d", &i, &j, &l, &r);
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
        sort(pos.begin(), pos.end());
        int lx = 0;
        int cnt = 0;
        ll ans = 0;
        for(auto it: ev){
            ans += ((ll)cnt)*(it.fst - lx);
            lx = it.fst;
            vector<pair<pair<bool, int>, int>> &v = it.snd;
            for(pair<pair<bool, int>, int> tp: v){
                int l, r;
                bool t = tp.fst.fst;
                l = tp.fst.snd;
                r = tp.snd;
                int p = lower_bound(pos.begin(), pos.end(), l) - pos.begin();
                if(!t){
                    ll ly = l;
                    ll lstval = 0;
                    while(l < r){
                        acc[l]++; 
                        if(lstval == k)
                            cnt += l - ly;
                        lstval = acc[l];
                        ly = l;
                        l = pos[++p];
                    }
                    if(lstval == k)
                        cnt += r+1 - ly;
                }
                else{
                    ll ly = l;
                    ll lstval = -1;
                    while(l < r){
                        acc[l]--; 
                        //assert(it->fst >= ly);
                        if(lstval == k-1)
                            cnt -= l - ly;
                        lstval = acc[l];
                        //assert(lstval >= 0);
                        ly = l;
                        l = pos[++p];
                    }
                    if(lstval == k-1)
                        cnt -= r+1 - ly;
                }
            }
        }
        printf("%lld\n", ans);
    }
}

