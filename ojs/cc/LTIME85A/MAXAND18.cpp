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
const ll IMP = LLONG_MAX;

int n, m;
int s[MAXN];

ll cnt[35];
ll dp[35][35];

ll go(ll i, int k){
    ll &r = dp[i][k];
    //printf("go %lld %d r %lld\n", i, k, r);
    if(r != -1)
        return r;
    r = 0;
    if(i == 31){
        if(k == 0)
            return r = 0;
        else
            return r = LLONG_MIN;
    }
    if(k)
        r = max(r, go(i+1, k-1) + cnt[i]*(1ll<<((ll)i)));
    r = max(r, go(i+1, k));
    return r;
}

ll redp[35][35];

ll re(ll i, int k){
    ll &r = redp[i][k];
    if(r != -1)
        return r;
    if(i == 31){
        if(k == 0)
            return r = 0;
        else
            return r = IMP;
    }
    ll sm = IMP, bg = IMP;
    if(go(i, k) == go(i+1, k) && re(i+1, k) != IMP)
        sm = 2*re(i+1, k);
    if(k && go(i, k) == go(i+1, k-1) + cnt[i]*(1ll<<((ll)i)) && re(i+1, k-1) != IMP){
        bg = 1 + 2*re(i+1, k-1);
    }
    //printf("re i %lld k %d sm %lld bg %lld\n", i, k, sm, bg);
    return r = min(sm, bg);
}


int main (){
    for_tests(t, tt){
        memset(dp, -1, sizeof(dp));
        memset(redp, -1, sizeof(redp));
        for(int a=0;a<=32;a++){
            cnt[a] = 0;
        }
        int k;
        scanf("%d%d", &n, &k);
        for(int a=0;a<n;a++){
            scanf("%d", s+a);
            int i = 0;
            while(s[a] > 0){
                if(s[a]&1)
                    cnt[i]++;
                s[a] /= 2;
                i++;
            }
        }
        go(0, k);
        printf("%lld\n", re(0, k));
    }
}

