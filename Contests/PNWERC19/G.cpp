#include "bits/stdc++.h"
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

const int MAXN = 412345;
const int del = 100000;

int n, k;
int s[MAXN];

ll pos[MAXN], t[MAXN], m[MAXN];

int main (){
	scanf("%d", &n);
    vector<tuple<int, int, int>> ev;
	for(int a=0;a<n;a++){
        char tp;
        scanf(" %c%lld%lld%lld", &tp, t+a, m+a, pos+a);
        t[a] -= pos[a];
        t[a] += del;
        ev.pb({t[a], 1, (tp=='h')});
        ev.pb({t[a]+m[a], 0, (tp=='h')});
	}
    sort(ev.begin(), ev.end());
    ll res = 0;
    int cnt[2];
    cnt[0] = cnt[1] = 0;
    for(auto [ign, tev, t]: ev){
        if(tev == 1){
            res += cnt[1-t];
            cnt[t]++;
        }
        else{
            cnt[t]--;
        }
    }
    printf("%lld\n", res);
    return 0;
}

