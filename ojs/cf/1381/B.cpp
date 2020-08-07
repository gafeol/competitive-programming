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

const int MAXN = 4123;

int n, m, k;
int s[MAXN];
int p[MAXN], sz[MAXN];
int mx[MAXN];

int raiz(int u){
    if(p[u] == u) return u;
    return p[u] = raiz(p[u]);
}

void join(int i, int j){
    i = raiz(i);
    j = raiz(j);
    if(i == j)
        return;

    if(sz[i] < sz[j]) swap(i, j);
    p[j] = i;
    mx[i] = max(mx[i], mx[j]);
    sz[i] += sz[j];
}

int dp[MAXN];
int pos[MAXN];

int main (){
    for_tests(t, tt){
        scanf("%d", &n);
        n = 2*n;
        for(int a=0;a<=n;a++){
            dp[a] = 0;
            p[a] = a;
            sz[a] = 1;
        }
        dp[0] = true;

        for(int a=1;a<=n;a++){
            scanf("%d", s+a);
            mx[a] = s[a];
            pos[s[a]] = a;
        }
        for(int a=1;a<=n;a++){
           if(pos[a] > 1){
                if(mx[raiz(pos[a]-1)] > a)
                    join(pos[a], pos[a]-1);
           }
        }

        for(int a=1;a<=n;a++){
            if(raiz(a) == a){
               for(int x=n-sz[a];x>=0;x--){
                   if(dp[x])
                       dp[x + sz[a]] = 1;
               }
            }
        }

        if(dp[n/2])
            puts("YES");
        else
            puts("NO");
    }
}

