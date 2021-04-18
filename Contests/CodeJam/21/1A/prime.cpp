#include "bits/stdc++.h"
using namespace std;
#define fst first
#define snd second
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;
#define eb emplace_back
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

const int MAXN = 100;
const double EPS = 1e-6;

int np;
ll n[MAXN], p[MAXN];
ll res = 0, tot;

void go(int i, int q, ll prod, ll sum){
    if(prod > tot - sum || i == np)
        return ;
    if(prod == tot - sum)
        res = max(res, prod);
    if(q < n[i]){
        if(log(prod) + log(p[i]) - EPS <= log(tot-sum-p[i])){
            go(i, q+1, prod*p[i], sum+p[i]);
        }
    }
    go(i+1, 0, prod, sum);
}

int main (){
    for_tests(t, tt){
        res = 0;
        tot = 0;
        scanf("%d", &np);
        for(int a=0;a<np;a++){
            scanf("%lld %lld", p+a, n+a);
            tot += p[a]*n[a];
        }
        go(0, 0, 1, 0);
        printf("Case #%d: %lld\n", tt, res);
    }
    return 0;
}

