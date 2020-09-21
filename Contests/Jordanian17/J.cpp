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

const int MAXN = 300005;
const int MAXK = 52;

int n, m, k;
char s[MAXN];
int acc[MAXN];
int ans[MAXN];

int dp[MAXN][MAXK];
int fixJmp[MAXN][MAXK];
int qtdFJ[MAXN][MAXK];


int go(int i, int jmp){
    if(i >= 3*n || jmp < 0) return INT_MIN;
    int &r = dp[i][jmp];
    if(r != -1) return r;
    r = i;
    fixJmp[i][jmp] = i;
    qtdFJ[i][jmp] = 0;
    if(jmp && i + jmp < 3*n){
        int pw = acc[i+jmp] - (i > 0 ? acc[i-1] : 0);
        if(pw > 1 || s[i+jmp] == '#'){
            fixJmp[i][jmp] = i;
            qtdFJ[i][jmp] = 0;
            r = go(i, jmp-1);
            return r;
        }
        else{
            r = go(i+jmp, jmp);
            fixJmp[i][jmp] = fixJmp[i+jmp][jmp];
            qtdFJ[i][jmp] = 1 + qtdFJ[i+jmp][jmp];
            return r;
        }
    }
    return r;
}

int nw;

int walls(int l, int r){
    return acc[r] - (l > 0 ? acc[l-1] : 0);
}

int re(int i, int jmp, int p=0){
    //printf("re i %d jmp %d p %d\n", i, jmp, p);
    int nxtFix = fixJmp[i][jmp];
    int pw = walls(i, nxtFix);
    if(pw + p >= nw){
        int l = 0, r = qtdFJ[i][jmp];      
        while(l < r){
            int m = (l + r)/2;
            int pos = i + m*jmp;
            if(p + walls(i, pos) >= nw)
                r = m; 
            else
                l = m+1;
        }
        //printf("    fez bb de i %d ate l %d walls %d  + p %d\n", i, i + l*jmp, walls(i, i+l*jmp), p);
        return l;
    }
    else
        return re(fixJmp[i][jmp], jmp-1, p+pw) + qtdFJ[i][jmp];
}

int main (){
    freopen("jumps.in", "r", stdin);
    for_tests(t, tt){
        scanf("%d%d", &n, &k);
        for(int a=0;a<=3*n;a++){
            for(int b=0;b<=k;b++){
                dp[a][b] = -1;
            }
        }
        nw = 0;
        for(int a=0;a<n;a++){
            scanf(" %c", s+a);
            nw += (s[a]=='#');
            s[a+n] = s[a];
            s[a+2*n] = s[a];
        }
        for(int a=0;a<3*n;a++){
            acc[a] = (a > 0 ? acc[a-1] : 0) + (s[a] == '#');
        }
        for(int a=0;a<n;a++){
            if(s[a] != '#'){
                int ate = go(a, k);
                if(acc[ate] - (a > 0 ? acc[a-1] : 0) < nw)
                    ans[a] = -1;
                else
                    ans[a] = re(a, k);
            }
            else{
                ans[a] = 0;
            }
            printf("%d ", ans[a]);
        }
        puts("");
    }
}
