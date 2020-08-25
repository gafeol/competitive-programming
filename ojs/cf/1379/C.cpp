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

ll n;
int m, k;
ll p[MAXN], q[MAXN];
int mrk[MAXN];

int main (){
    for_tests(t, tt){
        scanf("%lld%d", &n, &m);
        vector<tuple<ll, ll, ll>> s;
        for(int a=0;a<m;a++){
            mrk[a] = false;
            scanf("%lld%lld", p+a, q+a);
            s.pb({p[a], 0, a});
            s.pb({q[a], 1, a});
        }
        sort(s.begin(), s.end(), greater<tuple<ll,ll,ll>>());
        ll res = 0;
        ll ans = 0;
        ll cnt = 0;
        for(tuple<ll,ll,ll> tp: s){
            ll x, id, t;
            tie(x, t, id) = tp;
            if(t == 0){
                mrk[id] = true; 
                ans += x;
                res = max(res, ans);
                cnt++;
            }
            else{
                if(!mrk[id])
                    res = max(res, ans + p[id] + q[id]*(n - cnt-1));
                else
                    res = max(res, ans + q[id]*(n-cnt));
            }
            if(cnt == n) break;
        }
        printf("%lld\n", res);
    }
}

