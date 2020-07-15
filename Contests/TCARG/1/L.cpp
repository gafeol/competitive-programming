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

const int MAXN = 312;
const int INF = INT_MIN;
const int NCALC = INT_MAX;

int n, m, k;
int s[MAXN];
int M[MAXN][MAXN];

int dp[2*MAXN][MAXN][MAXN];

bool valid(int i, int j){
    return (i >= 0 && j >= 0 && i < n && j < n);
}

int go(int d, int i, int ii){
    int j = d - i;
    int jj = d - ii;
    if(!valid(i, j) || !valid(ii, jj))
        return INF;
    int &r = dp[d][i][ii];
    if(r != NCALC)
        return r;
    r = INF;
    
    int aux = M[i][j] + M[ii][jj];
    if(i == ii && j == jj){
        aux -= M[i][j];
    }

    if(i == n-1 && ii == n-1 && j == n-1 &&  jj == n-1){
        return r = aux;
    }

    for(int t=0;t<2;t++){
        for(int tt=0;tt<2;tt++){
            int nxt = go(d+1, i+t, ii+tt);
            if(nxt == INF) continue;
            r = max(r, aux + go(d+1, i+t, ii+tt));
        }
    }
    return r;
}

int main (){
	scanf("%d", &n);
    for(int d=0;d<=2*n;d++){
        for(int a=0;a<=n;a++){
            for(int b=0;b<=n;b++){
                dp[d][a][b] = NCALC;
            }
        }
    }
	for(int a=0;a<n;a++){
        for(int b=0;b<n;b++){
            scanf("%d", &M[a][b]);
        }
	}
    printf("%d\n", go(0, 0, 0));
}

