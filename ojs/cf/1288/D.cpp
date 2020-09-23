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
const ll modn = 1000000007;
inline ll mod(ll x) { return x % modn; }
#define IOS() ios::sync_with_stdio(0),cin.tie(0)

const int MAXN = 312345;

int n, m, k;
int s[MAXN][10];
int cnt[(1<<9)];
int shf;
int L, R;

inline bool go(int k){
    for(int a=0;a<(1<<m);a++)
        cnt[a] = 0;
    for(int a=0;a<n;a++){
        int msk = 0;
        for(int b=0;b<m;b++){
            msk *= 2;
            if(s[a][b] >= k)
                msk += 1;
        }
        cnt[msk] = a+1;
    }
    for(int u=0;u<(1<<m);u++){
        if(!cnt[u]) continue;
        int msk = u;
        int a = cnt[u]-1;
        for(int bm=0;bm<(1<<m);bm++){
            if((bm|msk) > msk) continue;
            msk ^= bm;
            cnt[msk] = a+1;
            msk ^= bm;
        }
    }
    for(int u=0;u<(1<<m);u++){
        if(!cnt[u]) continue;
        int msk = u;
        int a = cnt[u]-1;
        if(cnt[(msk^shf)]){
            //puts("deu bom");
            L = cnt[(msk^shf)];
            R = a+1;
            return true;
        }
    }
    return false;
}

int main (){
	scanf("%d%d", &n, &m);
    shf = 0;
    for(int i=0;i<m;i++){
        shf *= 2;
        shf += 1;
    }
	for(int a=0;a<n;a++){
        for(int b=0;b<m;b++){
            scanf("%d", &s[a][b]);
        }
	}
    //             123456789
    ll i = 0, j = 1000000000LL;
    while(i < j){
        ll mid = (i + j + 1)/2ll;
        if(go(mid))
            i = mid;
        else
            j = mid-1;
    }
    //printf("%lld\n", i);
    go(i);
    printf("%d %d\n", L, R);
}

