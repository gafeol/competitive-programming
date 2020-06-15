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

const int MAXN = 10000007;

int n, m, k;
int prv[MAXN];

ll s[MAXN];

int gcd(int a, int b){
    if(a == 0) return b;
    return gcd(b%a, a);
}

pii diss(ll x){
    ll ox = x;
    set<int> q;
    while(x > 1){
        //printf("x %d -> %d prv[x] %d\n", x, x/prv[x], prv[x]);
        q.insert(x/prv[x]);
        x = prv[x];
    }
    if(q.size() < 2)
        return {-1, -1};
   int pri = *q.begin();
   q.erase(q.begin());
   int seg = 1;
    while(q.size()){
        seg *= *q.begin();
        q.erase(q.begin());
    }
    if(gcd(pri+seg, ox) == 1)
        return {pri, seg};
    else
        return {-1, -1};
}

int main (){
    for(int i=2;i<MAXN;i++){
        if(prv[i] != 0) continue;
        prv[i] = 1;
        for(ll j=i;i*j < MAXN;j++)
            prv[i*j] = j; 
    }
	scanf("%d", &n);
    vector<pii> ans;
	for(int a=0;a<n;a++){
        scanf("%lld", s+a);
        pii p = diss(s[a]);
        ans.pb(p);
    }
    for(int a=0;a<n;a++){
        printf("%d ", ans[a].fst);
    }
    puts("");
    for(int a=0;a<n;a++){
        printf("%d ", ans[a].snd);
    }
    puts("");
}

