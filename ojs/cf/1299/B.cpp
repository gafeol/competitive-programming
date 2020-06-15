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
pll s[MAXN];

ll sq(ll x){
    return x*x;
}

ll dist(pll a, pll b){
    return sq(a.fst - b.fst) + sq(a.snd - b.snd);
}

bool par(pll a, pll aa, pll b, pll bb){
    pll va = {a.fst - aa.fst, a.snd - aa.snd};
    pll vb = {b.fst - bb.fst, b.snd - bb.snd};
    return (va.fst*vb.snd - va.snd*vb.fst == 0);
}

int main (){
	scanf("%d", &n);
	for(int a=0;a<n;a++){
        scanf("%lld%lld", &s[a].fst, &s[a].snd);
	}
    if(n&1){
        puts("NO");
        return 0;
    }
    bool ok = true;
    int stp = n/2;
    for(int a=0;a<n;a++){
        int aa = (a+1)%n;
        int b = (a+stp)%n;
        int bb = (b+1)%n;
        if(dist(s[a], s[aa]) != dist(s[b], s[bb]) || !par(s[a], s[aa], s[b], s[bb])){
            ok = false;
            break;
        }
    }
    if(ok)
        puts("YES");
    else
        puts("NO");
}

