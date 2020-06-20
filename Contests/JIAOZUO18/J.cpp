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
map<pii, int> cnt;

ll llSqrt(ll x){
    ll y = sqrt(x);
    if(y*y == x)
        return y;
    if((y+1)*(y+1) == x)
        return y+1;
    if((y-1)*(y-1) == x)
        return y-1;
    assert(false);
}

bool valid(int i){
    return (i >= 0 && i < n);
}

int solvePos(ll a, ll b, ll c){
    //printf("solve %lld %lld %lld\n", a, b, c);
    ll del = b*b - 4ll*a*c;
    ll sq = llSqrt(del);
    ll x1 = (-b - sq)/(2*a);
    ll x2 = (-b + sq)/(2*a);
    if((-b - sq)%4 != 0)
        x1 = -1;
    if((-b - sq)%4 != 0)
        x2 = -1;
    if(valid(x1))
        return x1;
    assert(valid(x2));
    return x2;
}

int main (){
    for_tests(t, tt){
        cnt.clear();
        scanf("%d%d", &n, &m);
        vector<vector<ll>> qtd(m+2, vector<ll>(m+2, 0));
        vector<vector<ll>> S(m+2, vector<ll>(m+2, 0));
        vector<vector<ll>> SS(m+2, vector<ll>(m+2, 0));
        for(ll a=0;a<n;a++){
            int i, ii, j, jj;
            scanf("%d%d%d%d", &j, &jj, &i, &ii);

            //printf("i %d j %d ii %d jj %d\n", i, j, ii, jj);
            qtd[ii][jj]++;
            S[ii][jj] += a;
            SS[ii][jj] += a*a;

            qtd[i-1][jj]--;
            S[i-1][jj] -= a;
            SS[i-1][jj] -= a*a;

            qtd[ii][j-1]--;
            S[ii][j-1] -= a;
            SS[ii][j-1] -= a*a;

            qtd[i-1][j-1]++;
            S[i-1][j-1] += a;
            SS[i-1][j-1] += a*a;
        }
        int cnt0 = 0;
        for(int i=m;i>0;i--){
            for(int j=m;j>0;j--){
                qtd[i][j] += qtd[i+1][j] + qtd[i][j+1] - qtd[i+1][j+1];
                S[i][j] += S[i+1][j] + S[i][j+1] - S[i+1][j+1];
                SS[i][j] += SS[i+1][j] + SS[i][j+1] - SS[i+1][j+1];
                if(qtd[i][j] == 1){
                    ll u = S[i][j];
                    cnt[{u,u}]++;
                }
                else if(qtd[i][j] == 2){
                    ll u = solvePos(2, -2*S[i][j], S[i][j]*S[i][j] - SS[i][j]);
                    ll v = S[i][j] - u;
                    assert(valid(v));
                    if(u > v)
                        swap(u, v);
                    //printf("i %d j %d S %lld SS %lld u %lld v %lld\n", i, j, S[i][j], SS[i][j], u, v);
                    cnt[{u,v}]++;
                }
                else if(qtd[i][j] == 0)
                    cnt0++;
            }
        }
        /*
        for(int a=1;a<=m;a++){
            for(int b=1;b<=m;b++){
                printf("%lld ", qtd[a][b]);
            }
            puts("");
        }
        */
        int res = m*m;
        int bst = 0, bst2 = 0;
        for(auto it: cnt){
            pii p = it.fst;
            if(p.fst == p.snd){
                //printf("p %d cnt %d\n", p.fst, cnt[p]);
                if(cnt[p] > bst){
                    bst2 = bst;
                    bst = cnt[p];
                }
                else if(cnt[p] > bst2){
                    bst2 = cnt[p];
                }
                continue;
            }
            //printf("pair %d %d poss cnt fst %d cnt snd %d cnt both %d\n", p.fst, p.snd, cnt[{p.fst, p.fst}], cnt[{p.snd, p.snd}], it.snd);
            res = min(res, m*m -cnt0 - cnt[{p.fst, p.fst}] - cnt[{p.snd, p.snd}] - it.snd);
        }
        res = min(res, m*m - cnt0 - bst - bst2);
        //printf("cnt 0 %d bst %d bst2 %d\n", cnt0, bst, bst2);
        printf("%d\n", res);
    }
}
