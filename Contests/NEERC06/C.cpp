#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
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
#define IOS() ios::sync_with_stdio(0),cin.tie(0)

const int MAXN = 512;

ll n, m, d, k;
inline ll mod(ll x) { return x % m; }
ll s[MAXN];
ll C[MAXN][MAXN];
ll M[MAXN][MAXN];
ll base[MAXN][MAXN];

inline void multBase(){
    for(int a=0;a<1;a++){
        for(int b=0;b<n;b++){
            C[a][b] = 0;
            for(int c=0;c<n;c++){
                C[a][b] = C[a][b] + M[a][c]*base[c][b];
            }
        }
    }
    for(int a=0;a<n;a++){
        for(int b=0;b<n;b++){
            C[a][b] = C[0][(b-a+n)%n];
            M[a][b] = mod(C[a][b]);
        }
    }
}
inline void mult(){
    //puts("Start mult");
    for(int a=0;a<1;a++){
        for(int b=0;b<n;b++){
            C[a][b] = 0;
            for(int c=0;c<n;c++){
                C[a][b] = C[a][b] + M[a][c]*M[c][b];
            }
        }
    }
    for(int a=0;a<n;a++){
        for(int b=0;b<n;b++){
            C[a][b] = C[0][(b-a+n)%n];
            M[a][b] = mod(C[a][b]);
        }
    }
    //puts("end mult");
}

inline void expo(ll e){
    //printf("expo %lld\n", e);
    if(e == 0)
        return;
    expo(e/2);
    mult();
    if(e&1)
        multBase();
    //printf("ok e %lld\n", e);
}

int main (){
    freopen("cell.in", "r", stdin);
    freopen("cell.out", "w", stdout);
	scanf("%lld%lld%lld%lld", &n, &m, &d, &k);
	for(ll a=0;a<n;a++){
        scanf("%lld", s+a);
        M[a][a] = 1;
        for(ll b=0;b<n;b++){
            if(min(abs(a + n - b), min(abs(a - b), abs(a - (b + n)))) <= d)
                base[a][b] = 1;
        }
	}
    //puts("leu tudo");
    expo(k);
    for(int a=0;a<n;a++){
        ll val = 0;
        for(int b=0;b<n;b++){
            val = mod(val + s[b] * M[a][b]); 
        }
        printf("%lld%c", val, " \n"[a==n-1]);
    }
}

