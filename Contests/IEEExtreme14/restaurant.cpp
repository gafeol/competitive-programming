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

const int MAXN = 212;

int n, m, k;
int s[MAXN];
char M[MAXN][MAXN];

int vi[] = {1, 0, -1, 0};
int vj[] = {0, 1, 0, -1};

bool valid(int i, int j){
    return (i>=0 && j>=0 && i < n && j < m);
}

int tempo;
int mrk[MAXN][MAXN];

int go(int i, int j){
    mrk[i][j] = tempo;
    int ans = 0;
    for(int d=0;d<4;d++){
        int ii = i + vi[d];
        int jj = j + vj[d];
        if(!valid(ii, jj)) continue;
        if(M[i][j] == '.' && M[ii][jj] == 'T')
            ans++;
        if(M[ii][jj] == '.' && mrk[ii][jj] != tempo)
            ans += go(ii, jj);
    }
    return ans;
}

int main (){
    for_tests(t, tt){
        scanf("%d%d", &n, &m);
        int is, js;
        for(int a=0;a<n;a++){
            for(int b=0;b<m;b++){
                scanf(" %c", &M[a][b]);
                if(M[a][b] == 'S'){
                    is = a;
                    js = b;
                }
            }
        }
        int res = 0;
        for(int bm=0;bm<(1<<(n*m));bm++){
            bool ok = true;
            for(int a=0;a<n && ok;a++){
                for(int b=0;b<m && ok;b++){
                    if((bm>>(a*m + b))&1){
                        if(M[a][b] == 'S' || M[a][b] == '#'){
                            ok = false;
                            break;
                        }
                        M[a][b] = 'T';
                    }
                }
            }
            if(ok){
                tempo++;
                res = max(res, go(is, js));
                //printf("bm %d res=max %d\n", bm, res);
            }
            for(int a=0;a<n;a++)
                for(int b=0;b<m;b++)
                    if(M[a][b] == 'T')
                        M[a][b] = '.';
        }
        printf("%d\n", res);
    }
    return 0;
}

