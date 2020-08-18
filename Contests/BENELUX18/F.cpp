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

int n, m;
ll k;
ll p[MAXN], c[MAXN];

bool go(ll d){
    ll res = 0;
    for(int a=0;a<n;a++){
        res += max(0ll, p[a]*d - c[a]);
        if(res >= k) 
            return true;
    }
    return (res >= k);
}

int main (){
	scanf("%d%lld", &n, &k);
	for(int a=0;a<n;a++)
        scanf("%lld%lld", p+a, c+a);
    ll i = 1, j = 3000000000LL;
    while(i < j){
        ll m = (i + j)/2ll;
        if(go(m))
            j = m; 
        else
            i = m+1;
    }
    printf("%lld\n", i);
}

