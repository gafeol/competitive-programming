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
pii s[MAXN];
int X, Y;
vector<int> ev[MAXN];

int mrk[MAXN];

int mx[MAXN];

int main (){
	scanf("%d%d", &X, &Y);
    scanf("%d", &n);

    int cnt = 0;
	for(int a=0;a<n;a++){
        int x, y;
        scanf("%d%d", &x, &y);
        s[a] = {y, x};
        ev[y].pb(x);
        mx[x] = max(mx[x], y);
	}
    ll ans = LLONG_MAX;
    ll acu = 0;
    ll baixo = 0;
    ll cima = 0;
    ll res = X-1;

    for(int a=0;a<X;a++){
        res += mx[a]*2ll; 
        cima += (mx[a] > 0);
    }

    for(int y =0;y<Y;y++){
        ans = min(ans, res);
        //debug("y %d res %lld cima %lld baixo %lld\n", y, res, cima, baixo);
        for(int x: ev[y]){
            if(!mrk[x]){
                mrk[x]++;
                baixo++;
            }
        }
        res += 2*(baixo - cima);
        if(y + 1 < Y){
            for(int x: ev[y+1]){
                if(mx[x] == y+1){
                    cima--;
                    mx[x] = INT_MAX;
                }
            }
        }
         
    }
    printf("%lld\n", ans);
}

