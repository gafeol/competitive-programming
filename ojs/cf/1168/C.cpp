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

const int MAXN = 300005;
const int BIT = 20;

int n, m, k;
int s[MAXN];
int dp[MAXN][BIT];
int nxt[MAXN][BIT];

int go(int i,int b){
    int &r = dp[i][b];
    if(r != -1)
        return r;
    r = n;
    if(i == n)
        return r = n;
    if((s[i] >> b)&1)
        return r = i;

    for(int bt=0;bt<BIT;bt++){
        if((s[i]>>bt)&1){
            r = min(r, go(nxt[i+1][bt], b));     
        }
    }
    return r;
}

int main (){
	scanf("%d%d", &n, &m);
	for(int a=0;a<n;a++)
        scanf("%d", s+a);

    for(int i=0;i<BIT;i++){
        nxt[n][i] = n;
    }
    for(int a=n-1;a>=0;a--){
        for(int i=0;i<BIT;i++){
            if((s[a]>>i)&1)
                nxt[a][i] = a;
            else
                nxt[a][i] = (a+1 < n ? nxt[a+1][i] : n);
        }
    }

    memset(dp, -1, sizeof(dp));

    for(int a=0;a<m;a++){
        int i, j;
        scanf("%d%d", &i, &j);
        i--;j--;
        bool ok = false;
        for(int b=0;b<BIT && !ok;b++){
            if(((s[j]>>b)&1) && go(i, b) <= j)
                ok = true;
        }
        if(ok)
            puts("Shi");
        else
            puts("Fou");
    }
}

