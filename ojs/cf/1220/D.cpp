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

int cnt[70], nn;
vector<ll> n[70];

int main (){
	scanf("%d", &nn);
	for(int a=0;a<nn;a++){
        ll x;
        scanf("%lld", &x);
        ll xx  = x;
        int t = 0;
        while(!(x&1)){
            t++;
            x/=2;
        }
        cnt[t]++;
        n[t].pb(xx);
	}
    int mx = 0;
    for(int a=1;a<70;a++){
        if(cnt[a] > cnt[mx])
            mx = a;
    }

    printf("%d\n", nn - cnt[mx]);
    for(int i=0;i<70;i++){
        if(i == mx) continue;
        for(ll x: n[i])
            printf("%lld ", x);
    }
    puts("");

}

