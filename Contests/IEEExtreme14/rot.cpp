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
#define IOS() ios::sync_with_stdio(0),cin.tie(0)

const int MAXN = 2123456;

int n, m;
ll k;
ll s[MAXN];
ull h;
ull pri = 1e9 + 7;

int main (){
    scanf("%d%lld", &n, &k);
    ull pot = 1;
    for(int a=0;a<n;a++){
        scanf("%lld", s+a);
        if(a > 0)
            s[a] -= s[0];
    }
    s[0] = 0;
    for(int a=1;a<n;a++){
        //printf("hash add %lld\n", (s[a] - s[a-1]));
        h = h*pri + (s[a] - s[a-1]);
        pot = pot*pri;
    }

    //printf("s[n-1] %lld\n", s[n-1]);
    ll sob = k-1 - s[n-1];

    ll ans = 0;
    //set<ll> q;
    vector<pair<ull,ll>> q(n);
    q[0]=make_pair(h,sob);
    debug("H %lld sob %lld\n", h, sob);
    for(int a=1;a<n;a++){
        h = h*pri;
        h = h - pot*(s[a] - s[a-1]);
        //printf("hash rmv %lld add %lld\n", s[a] - s[a-1], sob + 1);
        h += sob  + 1;
        sob = s[a] - s[a-1] - 1;
        debug("H %lld sob %lld\n", h, sob);
        q[a]=(make_pair(h,sob+1));
    }
    sort(q.begin(),q.end());
    for(int i=0;i<q.size();i++){
        if(i==0 || q[i].first!=q[i-1].first)ans+=q[i].second;
    }
    printf("%lld\n", ans);
    return 0;
}
