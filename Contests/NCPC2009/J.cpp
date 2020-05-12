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
#define div adasd
const ll modn = (1ll<<31ll) - 1ll;
inline ll mod(ll x) { return x % modn; }

const int MAXN = 212;

int n, m;
ll k;
int s[MAXN];

unordered_map<ll, ll> dp[110];
vector<int> div;

ll gcd(ll a, ll b){
    if(a == 0)
        return b;
    return gcd(b%a, a);
}


ll _lcm(ll a, ll b){
    return (a*b)/gcd(a, b);
}

ll ch[MAXN][MAXN], fat[MAXN];

ll go(int i, ll lcm){
    if(i < 0 || k%lcm != 0) 
        return 0;
    if(dp[i].find(lcm) != dp[i].end())
        return dp[i][lcm];
    ll &r = dp[i][lcm];
    r = 0;
    if(i == 0)
        return r = (lcm == k);
    for(int x: div){
        if(x > i) break;
        r = mod(r + mod(fat[x-1]*ch[i][x]) * go(i-x, _lcm(lcm, x)));
    }
    //printf("i %d lcm %lld r = %lld\n", i, lcm, dp[i][lcm]);
    return r;
}

int main (){
	scanf("%d%lld", &n, &k);

    ch[1][1] = 1;
    fat[0] = fat[1] = 1;
    for(ll a=2;a<=n;a++){
        fat[a] = mod(a*fat[a-1]);
        for(ll b=1;b<=a;b++){
            ch[a][b] = mod(ch[a-1][b] + ch[a-1][b-1]);
        }
    }
	for(int a=1;a<=n;a++){
        if(k%a == 0){
            div.pb(a);
        }
	}
    printf("%lld\n", go(n, 1));
}

