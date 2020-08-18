
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
#define IOS() ios::sync_with_stdio(0),cin.tie(0)

const int MAXN = 1123456;

int n, m, k;
ll l[MAXN];
ll w[MAXN];
ll h[MAXN];

int main (){
    for_tests(t, tt){
        scanf("%d%d", &n, &k);
        for(int a=0;a<k;a++)
            scanf("%lld", l+a);
        ll A, B, C, D;
        scanf("%lld%lld%lld%lld", &A, &B, &C, &D);
        for(int a=k;a<n;a++)
            l[a] = ((A*l[a-2] + B*l[a-1] + C)%D) + 1;

        for(int a=0;a<k;a++)
            scanf("%lld", w+a);
        scanf("%lld%lld%lld%lld", &A, &B, &C, &D);
        for(int a=k;a<n;a++)
            w[a] = ((A*w[a-2] + B*w[a-1] + C)%D) + 1;

        for(int a=0;a<k;a++)
            scanf("%lld", h+a);
        scanf("%lld%lld%lld%lld", &A, &B, &C, &D);
        for(int a=k;a<n;a++)
            h[a] = ((A*h[a-2] + B*h[a-1] + C)%D) + 1;

        ll ans = 1;
        ll per = 0;
        set<pll> q;
        q.insert({0, 0});
        q.insert({LLONG_MAX, LLONG_MAX});
        for(int a=0;a<n;a++){
            pll p = {l[a], l[a] + w[a]};
            auto bef = (--q.lower_bound({l[a], -1}));
            auto aft = q.upper_bound({l[a] + w[a], LLONG_MAX});
            bool leftFree = true;
            bool rightFree = true;
            while(bef != aft){
                if(bef->snd < p.fst || bef->fst > p.snd){
                    bef++;
                    continue;
                }
                if(bef->fst <= l[a] && bef->snd >= l[a])
                    leftFree = false;
                if(bef->fst <= l[a] + w[a] && bef->snd >= l[a] + w[a])
                    rightFree = false;
                ll x = bef->fst;
                if(x > l[a] && x <= l[a]+w[a])
                    per = mod(per - h[a]);
                x = bef->snd;
                if(x >= l[a] && x < l[a]+w[a])
                    per = mod(per - h[a]);

                p.fst = min(p.fst, bef->fst);
                p.snd = max(p.snd, bef->snd);


                if(bef->fst <= l[a] && l[a] + w[a] <= bef->snd){ // sobs
                    p = {0, 0};              
                    break;
                }

                auto prvbef = bef++;
                per = mod(per - 2*(prvbef->snd - prvbef->fst));
                q.erase(prvbef);
            }
            q.insert(p);
            per = mod(per + 2*(p.snd - p.fst));
            if(leftFree)
                per = mod(per + h[a]);
            if(rightFree)
                per = mod(per + h[a]);
            per = mod(modn + per);
            ans = mod(ans*per);
        }
        printf("Case #%d: ", tt);
        printf("%lld\n", ans);
    }
}

