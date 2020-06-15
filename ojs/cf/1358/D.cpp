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

const int MAXN = 412345;

int n, m;
ll k;
ll s[MAXN];
ll sum[MAXN];
ll val[MAXN];

ll soma(ll i, ll j){
    if(j < i) return 0;
    return ((i + j)*(j - i + 1))/2ll;
}
    
ll acu(int i, int j){
    if(i > j) return 0ll;
    return (j >= 0 ? sum[j] : 0) - (i-1 >= 0 ? sum[i-1] : 0);
}
ll acuval(int i, int j){
    if(i > j) return 0ll;
    return (j >= 0 ? val[j] : 0) - (i-1 >= 0 ? val[i-1] : 0);
}
int main (){
	scanf("%d%lld", &n, &k);
	for(int a=0;a<n;a++){
        scanf("%lld", s+a);
        s[a+n] = s[a];
	}
    n = 2*n;
    for(int a=0;a<n;a++){
        sum[a] = s[a] + (a > 0 ? sum[a-1] : 0);
        val[a] = soma(1, s[a]) + (a>0 ? val[a-1] : 0);
    }
    sum[n]  = sum[n-1];
    s[n] = 0;
    ll ans = 0;
    int i = 0, j = 0;
    while(i < n){
        j = max(j, i);
        while(j < n && acu(i, j-1) + s[j] <= k)
            j++;
        ll sob = k - acu(i, j-1);
        ll extra = 0;
        if(j < n)
            extra = soma(1, sob);
        //printf("vai de %d ate %d da %lld sobra %lld extra %lld\n", i, j-1, acuval(i, j-1), sob, extra);
        ans = max(ans, acuval(i, j-1) + extra);
        i++;
    }

    i = n-1;
    j = n-1;
    while(j >= 0){
        i = min(i, j);
        while(i >= 0 && acu(i+1, j) + s[i] <= k)
            i--; 
        ll sob = k - acu(i+1, j);
        ll extra = 0;
        if(i >= 0)
            extra = soma(s[i]-sob+1, s[i]);
        //printf("vai de %d ate %d da %lld sobra %lld extra %lld\n", i+1, j, acuval(i+1, j), sob, extra);
        ans = max(ans, acuval(i+1, j) + extra);
        j--;
    }
    printf("%lld\n", ans);
}

