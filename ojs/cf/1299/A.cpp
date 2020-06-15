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

const int MAXN = 212345;

int n, m, k;
int s[MAXN];
ll o[MAXN];
ll inv[MAXN];

ll f(int i){
    ll bef = (i > 0 ? o[i-1] : 0);
    ll aft = inv[i+1];
    ll ans = (s[i]^(s[i]&(bef|aft)));
    //printf("i %d ans %lld bef aft %lld %lld\n", i, ans, bef, aft);
    return ans;
}

int main (){
	scanf("%d", &n);
	for(int a=0;a<n;a++){
        scanf("%d", s+a);
        o[a] = (a > 0 ? o[a-1] : 0);
        o[a] |= s[a];
	}
    for(int a=n-1;a>=0;a--){
        inv[a] = (inv[a+1] | s[a]);
    }
    int big = 0;
    for(int a=1;a<n;a++){
        if(f(a) > f(big))
            big = a;
    }
    printf("%d ", s[big]);
    for(int a=0;a<n;a++){
        if(a == big) continue;
        printf("%d ", s[a]);
    }
    puts("");
}

