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
inline ll mod(ll x) { return x % modn; }
#define IOS() ios::sync_with_stdio(0),cin.tie(0)

const int MAXN = 212345;

int n, m, k;
int s[MAXN];

vector<ll> p = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97};

int main (){

    pll best = {LLONG_MAX, LLONG_MAX};
    for(int bm=0;bm<(1<<p.size());bm++){
        ll val[] = {1, 1};
        for(int i=0;i<p.size();i++){
            int t = ((bm&(1<<i)) > 0);
            if(log(val[t]) + log(p[i]) >= log(2e18)){
                val[0] = val[1] = LLONG_MAX;
                break;
            }
            val[t] *= p[i];
        }
        sort(val, val+2);
        if(best > make_pair(val[1], val[0]))
            best = {val[1], val[0]};
    }
    printf("%lld %lld\n", best.fst, best.snd);
    printf("eh menor %d\n", best.fst < (ll)2e18);
}

