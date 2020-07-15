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

const int MAXN = 112345;

int n, m;
int x;
ll s[MAXN];
ll acc[MAXN];

inline ll count(int k){
    ll ans = 0;
    unordered_map<int, int> cnt;
    int dim = x/k;
    //printf("count %lld dim %d\n", k, dim);
    for(int a=dim-1;a<n;a++){
        ll val = acc[a] - (a-dim >= 0 ? acc[a-dim]:0);
        if(val <= k)
            cnt[(int)val]++;
    }
    for(int a=dim-1;a<n;a++){
        ll val = acc[a] - (a-dim >= 0 ? acc[a-dim]:0);
        ll o = k - val;
        //printf("a %d val %lld oo %lld\n", a, val, o);
        if(o >= 0 && cnt.find(o) != cnt.end())
            ans += cnt[o];
    }
    //printf("ans %lld\n", ans);
    return ans;
}

int main (){
    for_tests(t, tt){
        scanf("%d%d", &n, &x);
        for(int a=0;a<n;a++){
            scanf("%lld", s+a);
            acc[a] = s[a];
            if(a > 0)
                acc[a] += acc[a-1];
        }
        ll res = 0;
        for(int div=1;div<=sqrt(x)+1 && div <= x;div++){
            if(x%div != 0) continue;
            int odiv = x/div;
            if(odiv < div) break;
            res += count(odiv); 
            if(odiv != div)
                res += count(div);
        }
        printf("%lld\n", res);
    }
}

