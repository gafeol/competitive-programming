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
#define debug(args...) //fprintf(stderr,args)
#else
#define debug(args...)
#endif //ONLINE_JUDGE
template<typename T> inline T abs(T t) { return t < 0? -t : t; }
const ll modn = 1000000007;
inline ll mod(ll x) { return x % modn; }

const int MAXN = 112345;

int n, m, k;
int s[MAXN];

int bit[MAXN];
int biti[MAXN];

int qry(int i){
    i += 2;
    int ans = 0;
    while(i < MAXN){
        ans += bit[i]; 
        i += (i&-i);
    }
    return ans;
}

int qryi(int i){
    i += 2;
    int ans = 0;
    while(i > 0){
        ans += biti[i];
        i -= (i&-i);
    }
    return ans;
}

void upd(int i, int val){
    i += 2;
    while(i > 0){
        bit[i] += val;
        i -= (i&-i);
    }
}

void updi(int i, int val){
    i += 2;
    while(i < MAXN){
        biti[i] += val;
        i += (i&-i);
    }
}

ll ninv(ll k){
    ll res = 0;
    int i = 1, j = 0;
    ll cnt = 0;
    debug("========== ninv <= %d\n", k);
    while(i <= n){
        while(j + 1 <= n && cnt + qry(s[j+1]+1) <= k){
            j++;
            debug("posso add j %d pq cnt %lld + %d <= %lld\n", j, cnt, qry(s[j]+1), k);
            cnt += qry(s[j] + 1);
            upd(s[j], 1);
            updi(s[j], 1);
        }
        
        debug("de i %d  a j %d (%lld inv)\n", i, j, cnt);
        res += j - i + 1;

        cnt -= qryi(s[i]-1);
        upd(s[i], -1);
        updi(s[i], -1);
        i++;
    }
    debug("ninv <= %lld eh ", k);
    debug("%lld\n", res);
    return res;
}

int main (){
    for_tests(t, tt){
        for(int a=0;a<MAXN;a++){
            bit[a] = biti[a] = 0;
        }
        scanf("%d", &n);
        vector<int> val;

        for(int a=1;a<=n;a++){
            scanf("%d", s+a);
            val.pb(s[a]);
        }
        sort(val.begin(), val.end());
        val.erase(unique(val.begin(), val.end()), val.end());
        for(int a=1;a<=n;a++)
            s[a] = lower_bound(val.begin(), val.end(), s[a]) - val.begin();
        ll i = 0, j = ((ll)n)*((ll)n);
        ll mid = (((ll)n)*(n+1ll))/2ll;
        mid = (mid+1)/2ll;
        while(i < j){
            ll m = (i + j)/2;
            if(ninv(m) >= mid)
                j = m;
            else
                i = m + 1;
        }
        printf("%lld\n", i);
    }
}

