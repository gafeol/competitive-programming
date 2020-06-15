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

const int MAXN = 212345, MAXK = 110;

int n, m, k;
int s[MAXN];

int bit[MAXK];

int qry(int i){
    i += 2;
    int ans = 0;
    while(i < MAXN){
        ans += bit[i];
        i += (i&-i);
    }
    return ans;
}

void upd(int i){
    i+=2;
    while(i > 0){
        bit[i]++;
        i -= (i&-i);
    }
}

int inv[MAXN][MAXK];
int cnt[MAXK], icnt[MAXK];
int jafoi[MAXN], falta[MAXN];

ll dp[MAXN][MAXK][2];

ll go(int i, int k, bool ig){
    ll &r = dp[i][k][ig];
    if(r != -1)
        return r;
    if(i == n)
        return r = 0;
    r = 0;
    if(s[i] == 0 && k > 1)
        r = max(r, go(i, k-1, 0));
    r = max(r, go(i+1, k, 1) + inv[i][k] - ig);
    //printf("go %d %d pag %d val %lld\n", i, k, pagou, r);
    return r;
}

void re(int i, int k, bool pagou){
    ll r = go(i, k, pagou);
    if(i == n)
        return ;
    if(s[i] == 0 && k > 1 && r == go(i, k-1, 1) + (1-pagou)*((ll)falta[i])*((ll)jafoi[i])){
        printf("diminui valor, ganha %lld\n", (1-pagou)*((ll)falta[i])*((ll)jafoi[i]));
        return re(i, k-1, 1);
    }
    printf("coloca valor %d ganha %d\n", k, inv[i][k]);
    printf("%d\n", (s[i] == 0 ? k : s[i]));
    re(i+1, k, 0);
    //printf("go %d %d pag %d val %lld\n", i, k, pagou, r);
}


int main (){
    memset(dp, -1, sizeof(dp));
	scanf("%d%d", &n, &k);
    int holes = 0;
	for(int a=0;a<n;a++){
        scanf("%d", s+a);
        if(s[a])
            icnt[s[a]]++;
        else
            holes++;
	}
    ll res = 0;
    for(int a=0;a<n;a++){
        if(a > 0)
            jafoi[a] = jafoi[a-1] + (s[a-1] == 0);
        else
            jafoi[a] = 0;
        falta[a] = holes - jafoi[a];
        if(s[a]){
            icnt[s[a]]--;
            cnt[s[a]]++;
            res += qry(s[a]+1); 
            upd(s[a]);
        }
        else{
            int aux = 0;
            for(int v=1;v<=k;v++)
                aux += cnt[v];
            for(int v=1;v<=k;v++){
                aux -= cnt[v];
                aux += icnt[v-1];
                inv[a][v] = aux;
            }
        }
    }
    printf("%lld\n", res + go(0, k, 0));
    re(0, k, 0);
}

