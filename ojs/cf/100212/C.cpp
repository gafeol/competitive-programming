#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include "bits/stdc++.h"
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

const int MAXN = 2009;
const ll INF = (ll)3e17;

int n;
ll dp[MAXN][MAXN];
int ch[MAXN][MAXN];
ll s[MAXN], acc[MAXN];

inline ll sum(int i, int j){
    return acc[j] - (i > 0 ? acc[i-1] : 0);
}

bool code[MAXN];

void solve(int i, int j, int sz=0){
    if(i > j) return;
    if(i == j){
        for(int a=0;a<sz;a++)
            printf("%d", (int)code[a]);
        puts("");
        return ;
    }
    //printf("i %d j %d add 0\n", i, j);
    if(ch[i][j] < j){
        code[sz] =  0;
        solve(i, ch[i][j], sz+1);
        code[sz] = 1;
        //printf("i %d j %d rmv 0 add 1\n", i, j);
        solve(ch[i][j]+1, j, sz+1);
    }
    else{
        assert(false);
    }
}

int main (){
#ifdef ONLINE_JUDGE
    freopen("codes.in", "r", stdin);
    freopen("codes.out", "w", stdout);
#endif
	scanf("%d", &n);
    for(int a=0;a<=n+1;a++){
        for(int b=0;b<=n+1;b++){
            dp[a][b] = INF;
            ch[a][b] = -1;
        }
    }
	for(int a=0;a<n;a++){
        scanf("%lld", s+a);
        dp[a][a] = 0;
        ch[a][a] = a;
	}
    partial_sum(s, s+n, acc);
    for(int sz=2;sz<=n;sz++){
        for(int i=0;i+sz-1<n;i++){
            int j = i+sz-1;        
            for(int k=ch[i][j-1];k<=ch[i+1][j];k++){
                if(dp[i][j] > dp[i][k] + dp[k+1][j] + sum(i, j)){
                    dp[i][j] = dp[i][k] + dp[k+1][j] + sum(i, j);
                    ch[i][j] = k;
                }
            }
            if(ch[i][j] < i || ch[i][j] == j){
                printf("i %d j %d ch %d dp %lld\n", i, j, ch[i][j], dp[i][j]);
                return 0;
            }
            //assert(ch[i][j] >= i && ch[i][j] < j);
        }
    }
    solve(0, n-1);
    return 0;
}

