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

int n, k;
ll m;
int s[MAXN];

int main (){
	scanf("%d%lld", &n, &m);
    if(n == 1){
        if(m == 0)
            puts("1");
        else
            puts("-1");
        return 0;
    }
    ll cnt = 0;
    vector<ll> ans;
    ans.pb(1);
    ans.pb(2);
    while(cnt  + (ll)ans.size()/2 <= m){
        if(ans.size() > n){
            puts("-1");
            return 0;
        }
        cnt += (int)ans.size()/2;
        ans.pb(ans.size()+1);
    }
    if(m != cnt){
        int falta = m - cnt;
        ans.pb(ans[ans.size()-falta*2] + ans.back());
    }
    if(ans.size() > n){
        puts("-1");
        return 0;
    }
    ll stp = ans.back()+1;
    ll novo = 70000000LL;
    while(ans.size() < n){
        if(novo > 1000000000LL){
            puts("-1");
            return 0;
        }
        ans.pb(novo);
        novo += stp;
    }
    for(ll x: ans){
        printf("%lld ", x);
    }
    puts("");

}

