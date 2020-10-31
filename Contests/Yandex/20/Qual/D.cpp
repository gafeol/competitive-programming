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
const ll modn = 1000000007;
inline ll mod(ll x) { return x % modn; }
#define IOS() ios::sync_with_stdio(0),cin.tie(0)

const int MAXN = 212345;

int n, m, k, r;
ll s[MAXN];
multiset<ll> q[2];
ll sum[2];

void add(int t, ll x){
    q[t].insert(x);
    sum[t] += x;
}

ll rmv(int t){
    ll x = *q[t].begin();
    q[t].erase(q[t].begin());
    sum[t] -= x;
    return x;
}

int main (){
	scanf("%d%d%d", &n, &k, &r);
	for(int a=0;a<n;a++){
        scanf("%lld", s+a);
        add((a>=k), s[a]);
	}
    while(r--){
        ll x = rmv(0);
        x += sum[0];
        add(1, x);
        x = rmv(1);
        add(0, x);
    }
    bool fst = true;
    for(int t=0;t<2;t++){
        while(!q[t].empty()){
            if(!fst)
                printf(" ");
            printf("%lld", *q[t].begin());
            q[t].erase(q[t].begin());
            fst = false;
        }
    }
    puts("");
    return 0;
}

