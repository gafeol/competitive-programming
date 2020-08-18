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

const int MAXN = 100;

int n, m, k;
char s[MAXN];
ll dp[MAXN][10][2];

int tam;

ll go(int i, int d, bool lo){
    ll &r = dp[i][d][lo];
    if(r != -1)
        return r;
    if(i == tam)
        return lo;
    r = 0;
    for(int dig=d;dig<=9;dig++){
        if(!lo && dig > s[i]-'0') break;
        r += go(i+1, dig, (lo || dig < s[i]-'0'));
    }
    return r;
}

int main (){
	scanf("%d", &n);
	for(int a=0;a<n;a++){
        scanf(" %s", s);
        tam = strlen(s);
        int mx = 0;
        bool ok = true;
        for(int i=0;i<tam;i++){
            if(mx > s[i]-'0'){
                ok = false;
            }
            mx = max(mx, s[i]-'0');
        }
        if(!ok){
            puts("-1");
            continue;
        }
        memset(dp, -1, sizeof(dp));
        printf("%lld\n", go(0, 0, 0));
	}
}

