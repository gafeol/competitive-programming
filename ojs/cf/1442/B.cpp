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
const ll modn = 998244353;
inline ll mod(ll x) { return x % modn; }
#define IOS() ios::sync_with_stdio(0),cin.tie(0)

const int MAXN = 212345;

int n, m, k;
int s[MAXN];
int f[MAXN];

bool blc[MAXN];
int pos[MAXN];

int nw(int i){
    int cnt = 0;
    if(i-1 >= 0 && !blc[i-1])
        cnt++;
    if(i+1 < n && !blc[i+1])
        cnt++;
    return cnt;
}

int main (){
    for_tests(t,tt){
        scanf("%d%d", &n, &k);
        for(int a=0;a<n;a++){
            scanf("%d", s+a);
            pos[s[a]] = a;
            blc[a] = 0;
        }
        for(int a=0;a<k;a++){
            scanf("%d", f+a);
            blc[pos[f[a]]] = 1;
        }
        ll res = 1;
        for(int a=0;a<k;a++){
            res = mod(res*nw(pos[f[a]]));
            blc[pos[f[a]]] = false;
        }
        printf("%lld\n", res);
    }
    return 0;
}

