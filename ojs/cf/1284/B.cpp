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

const int MAXN = 1023456;

int n, m, k;
vector<int> s;
ll bit[MAXN];

void upd(int i){
    i+=2;
    while(i > 0){
        bit[i]++;
        i -= (i&-i);
    }
}

ll qry(int i){
    i += 2;
    ll ans = 0;
    while(i < MAXN){
       ans += bit[i]; 
       i += (i&-i);
    }
    return ans;
}

int main (){
	scanf("%d", &n);
    ll res = 0;
    ll cnt = 0;
	for(int a=0;a<n;a++){
        int mn = INT_MAX, mx = INT_MIN;
        scanf("%d", &m);
        bool has = false;
        while(m--){
            int x;
            scanf("%d", &x);
            if(mn < x)
                has = true;    
            mn = min(mn, x);
            mx = max(mx, x);
        }
        if(has){
            cnt++;
        }
        else{
            s.pb(mn);     
            upd(mx);
        }
	}
    res += cnt*cnt + cnt*((ll)n-cnt)*2ll;
    for(int x: s){
        res += qry(x+1);
    }
    printf("%lld\n", res);
}

