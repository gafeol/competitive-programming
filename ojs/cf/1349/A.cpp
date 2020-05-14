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

int n, m, k;
int s[MAXN];
int prv[MAXN];

unordered_map<int, vector<int> > cnt;

void add(int x){
    unordered_map<int, int> cntP;
    while(x > 1){
        cntP[prv[x]]++; 
        x/=prv[x];
    }
    for(auto it: cntP)
        cnt[it.fst].pb(it.snd);
}

ll gcd(ll a, ll b){
    if(a == 0) return b;
    return gcd(b%a, a);
}

ll mmc(ll a, ll b){
    return (a*b)/gcd(a, b);
}

ll expo(ll base, ll e){
    if(e == 0)
        return 1ll;
    ll ans = expo(base, e/2ll);
    ans = ans*ans;
    if(e&1)
        ans = ans*base;
    return ans;
}

int main (){
    for(int a=2;a<MAXN;a++){
        if(prv[a]) continue;
        prv[a] = a;
        for(ll b=a;b*a < MAXN;b++){
            prv[a*b] = a;
        }
    }
	scanf("%d", &n);
	for(int a=0;a<n;a++){
        scanf("%d", s+a);
        add(s[a]);
	}
    if(n == 2){
        printf("%lld\n", mmc(s[0], s[1]));
        return 0;
    }
    ll res = 1;
    for(auto it: cnt){
        vector<int> &qtd = it.snd;
        if(qtd.size() < n-1)
           continue;
        sort(qtd.begin(), qtd.end());
        if(qtd.size() == n-1)
            res *= expo(it.fst, qtd[0]); 
        else
            res *= expo(it.fst, qtd[1]);
        //printf("p %d res %lld\n", it.fst, res);
    }
    printf("%lld\n", res);
}

