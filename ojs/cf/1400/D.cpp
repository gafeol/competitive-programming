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

const int MAXN = 3123;

int n, m, k;
int s[MAXN];
ll cnt[MAXN][MAXN];
ll inv[MAXN][MAXN];

int main (){
    for_tests(t, tt){
        scanf("%d", &n);
        for(int a=0;a<=n+1;a++){
            for(int b=0;b<=n+1;b++){
                cnt[a][b] = 0;
                inv[a][b] = 0;
            }
        }
        for(int a=1;a<=n;a++){
            scanf("%d", s+a);
            for(int v=0;v<=n;v++)
                cnt[a][v] = cnt[a-1][v];
            cnt[a][s[a]]++;
        }
        for(int a=n;a>=1;a--){
            for(int v=0;v<=n;v++)
                inv[a][v] = inv[a+1][v];
            inv[a][s[a]]++;
        }
        ll res = 0;
        for(int a=1;a<=n;a++){
            for(int b=a+1;b<=n;b++){
                ll prvB = cnt[a-1][s[b]];                    
                ll posA = inv[b+1][s[a]];
                res += prvB*posA;
            }
        }
        printf("%lld\n", res);
    }
}

