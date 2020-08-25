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

const int MAXN = 212345;

int n, m, k;
int s[MAXN];
ll c, cc;
ll p, pp;

bool go(int q){
    ll qn = min(n, q);
    ll qm = q - qn;
    ll tot = qn*p + qm*pp;
    ll cry = 0;
    for(int a=0;a<=qn;a++){
        if(a*p > c) break;
        ll sob = c - a*p;
        ll usa = min(qm, sob/pp);
        cry = max(cry, a*p + usa*pp);
    }
    assert(cry <= c);
    return (tot-cry <= cc);
}

int main (){
    for_tests(t, tt){
        scanf("%lld%lld", &c, &cc);
        scanf("%d%d", &n, &m);
        scanf("%lld%lld", &p, &pp);
        if(p > pp){
            swap(n, m);
            swap(p, pp);
        }
        int i = 0, j = n+m;
        while(i < j){
            int mid = (i + j + 1)/2;
            if(go(mid))
                i = mid;
            else
                j = mid-1;
        }
        printf("%d\n", i);
    }
}

