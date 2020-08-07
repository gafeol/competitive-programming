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

const int EPS = 2000;
const int MAXN = 4003;

int n, m, k;
int s[MAXN];
char ori[MAXN][MAXN];
char M[MAXN][MAXN];
int sq[MAXN][MAXN];

pii toNew(pii old){
    return {old.fst + old.snd+1, EPS + old.fst - old.snd+1};
}

pii toOld(pii n){
    int x = (n.fst + n.snd - EPS-2)/2;
    return {x, n.fst - x-1};
}

int main (){
	scanf("%d%d", &n, &m);
	for(int a=0;a<n;a++){
        for(int b=0;b<m;b++){
            scanf(" %c", &ori[a][b]);
            pii nCord = toNew({a, b});
            M[nCord.fst][nCord.snd] = ori[a][b];
        }
	}
    ll ans = 0;
    for(int a=1;a<MAXN;a++){
        for(int b=1;b<MAXN;b++){
            if(M[a][b] == 0) continue;
            sq[a][b] = 1;
            if(M[a-1][b-1] == M[a][b]){
                if(a >= 2 && b >= 2 && M[a-2][b] == M[a][b] && M[a][b-2] == M[a][b])
                    sq[a][b] = 1 + min(sq[a-1][b-1], min(sq[a-2][b], sq[a][b-2])); 
                else
                    sq[a][b] = 2;
            }
            ans += 1 + (sq[a][b]-1)/2;
            pii oldc = toOld(make_pair(a, b));
            //printf("(%d %d) %d %d ans %d\n", a, b, oldc.fst, oldc.snd, 1 + (sq[a][b]-1)/2);
            //printf("sq %d\n", sq[a][b]);
        }
    }
    printf("%lld\n", ans);
}

