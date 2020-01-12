#include <bits/stdc++.h>
using namespace std;
#define fst first
#define snd second
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;
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
inline ll mod(ll x) { return x % modn; }

const int MAXN = 212345;

int n, m, k;
int s[MAXN];

ll h[MAXN];
ll h2[MAXN];


pll go(vector<tuple<int, int, int> > &v){
    ll x = 0;
    ll x2 = 0;
    ll sum = 0;
    ll sum2 = 0;
    sort(v.begin(), v.end());
    for(tuple<int, int, ll> tp: v){
        int i, t, id;
        tie(i, t, id) = tp;
        if(!t){
            ll hx = h[id];
            x = mod(x + mod(sum*hx));
            sum = mod(sum + hx);
            hx = h2[id];
            x2 = mod(x2 + mod(sum2*hx));
            sum2 = mod(sum2 + hx);
        }
        else{
            ll hx = h[id];
            sum -= hx;
            sum = mod(modn + mod(sum)); 
            hx = h2[id];
            sum2 -= hx;
            sum2 = mod(modn + mod(sum2)); 
        }
    }
    return {x, x2};
}

int main (){
    srand(time(NULL));
	scanf("%d", &n);
    vector<tuple<int, int, int> > ev, evv;
	for(int a=0;a<n;a++){
        int i, ii, j, jj;
        scanf("%d%d%d%d", &i, &j, &ii, &jj);
        ll b = (rand()+1)%modn, c = (rand()+1)%modn, d = (rand()+1)%modn;
        h[a] = mod(mod(b*c)*d + rand()%modn);
        if(h[a] == 0)
            h[a]++;
        b = (rand()+1)%modn; c = (rand()+1)%modn; d = (rand()+1)%modn;
        h2[a] = mod(mod(b*c)*d + rand()%modn);
        if(h2[a] == 0)
            h2[a]++;
        ev.pb({i, 0, a});
        ev.pb({j, 1, a});
        evv.pb({ii, 0, a});
        evv.pb({jj, 1, a});
	}
    pll ans = go(ev);
    pll x = go(evv);
    //printf("x %lld %lld ans %lld %lld\n", x.fst, x.snd, ans.fst, ans.snd);
    if(x == ans)
        puts("YES");
    else
        puts("NO");
}

