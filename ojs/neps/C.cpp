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

const int MAXN = 360;
const int INF = 0x3f3f3f3f;

#define R 1
#define L 0

int n, m, k;
//    i    j    d    bm    p
int dp[2][MAXN][2][(1<<4)][6];

char M[MAXN][MAXN];
int X[MAXN][MAXN];

map<char, int> ic;

bool ingrid(int i, int j){
    return (i >= 0 && j >= 0 && i < n && j < m);
}

int nxtbm(int bm, int i, int j, int p){
    if(!ingrid(i, j)) return -1;
    p = max(0, p-1);
    if(p > 0){
        assert(bm == 0);
        return bm;
    }
    else{
        if((1<<ic[M[i][j]])&bm)
            return -1;
        if(M[i][j] == ' ')
            return bm;
        return ((1<<ic[M[i][j]])|bm);
    }
}

int main (){
    ic['N'] = 0;
    ic['O'] = 1;
    ic['K'] = 2;
    ic['A'] = 3;
    ic[' '] = 4;
	scanf("%d%d%d", &n, &m, &k);
	for(int a=0;a<n;a++){
        for(int b=0;b<m;b++){
            M[a][b] = ' ';
            X[a][b] = 0;
            char s[10];
            scanf(" %s", s);
            if(strlen(s) == 1 && s[0] >= 'A' && s[0] <= 'Z'){
                M[a][b] = s[0];
            }
            else{
                X[a][b] = atoi(s);
            }
        }
	}
    for(int i=0;i<2;i++){
        for(int j=0;j<m;j++){
            for(int d=0;d<2;d++){
                for(int bm=0;bm<(1<<4);bm++){
                    for(int p=0;p<=k;p++){
                        dp[i][j][d][bm][p] = -INF;
                    }
                }
            }
        }
    }
    dp[0][0][R][0][0] = 0;
    dp[0][0][L][0][0] = 0;
    for(int ii=0;ii<n;ii++){
        int i = (ii&1);
        for(int j=0;j<m;j++){
            for(int d=0;d<2;d++){
                for(int bm=0;bm<(1<<4);bm++){
                    for(int p=0;p<=k;p++){
                        dp[i^1][j][d][bm][p] = -INF;
                    }
                }
            }
        }
        for(int d=0;d<2;d++){
            if(d == L){
                for(int j=m-1;j>=0;j--){
                    for(int bm=(1<<4)-1;bm>=0;bm--){
                        for(int p=0;p<=k;p++){
                            int &r = dp[i][j][d][bm][p];
                            if(r == -INF) continue;
                            r += (p == 0)*(X[ii][j]);
                            // Desce
                            int nbm = nxtbm(bm, ii+1, j, p);
                            int np = max(0, p-1);
                            if(nbm > -1){
                                int &nxt = dp[i^1][j][0][nbm][np];
                                nxt = max(nxt, r);
                                int &nxt2 = dp[i^1][j][1][nbm][np]; 
                                nxt2 = max(nxt2, r);
                            }
                            // Esquerda
                            nbm = nxtbm(bm, ii, j-1, p); 
                            np = max(0, p-1);
                            if(nbm > -1){
                                int &nxt = dp[i][j-1][d][nbm][np];
                                nxt = max(nxt, r);
                            }

                            // explode NOKA
                            if(bm == (1<<4)-1){
                                // Desce
                                int np = max(0, p-1);
                                if(ingrid(ii+1, j)){
                                    int &nxt = dp[i^1][j][0][0][k];
                                    nxt = max(nxt, r);
                                    int &nxt2 = dp[i^1][j][1][0][k]; 
                                    nxt2 = max(nxt2, r);
                                }
                                // Esquerda
                                if(ingrid(ii, j-1)){
                                    int &nxt = dp[i][j-1][d][0][k];
                                    nxt = max(nxt, r);
                                }

                            }
                        }
                    }
                }
            }
            else{
                for(int j=0;j<m;j++){
                    for(int bm=(1<<4)-1;bm>=0;bm--){
                        for(int p=0;p<=k;p++){
                            int &r = dp[i][j][d][bm][p];
                            if(r == -INF) continue;
                            r += (p == 0)*(X[ii][j]);
                            // Desce
                            int nbm = nxtbm(bm, ii+1, j, p);
                            int np = max(0, p-1);
                            if(nbm > -1){
                                int &nxt = dp[i^1][j][0][nbm][np];
                                nxt = max(nxt, r);
                                int &nxt2 = dp[i^1][j][1][nbm][np]; 
                                nxt2 = max(nxt2, r);
                            }
                            // Direita
                            nbm = nxtbm(bm, ii, j+1, p); 
                            np = max(0, p-1);
                            if(nbm > -1){
                                int &nxt = dp[i][j+1][d][nbm][np];
                                nxt = max(nxt, r);
                            }

                            // explode NOKA
                            if(bm == (1<<4)-1){
                                // Desce
                                int np = max(0, p-1);
                                if(ingrid(ii+1, j)){
                                    int &nxt = dp[i^1][j][0][0][k];
                                    nxt = max(nxt, r);
                                    int &nxt2 = dp[i^1][j][1][0][k]; 
                                    nxt2 = max(nxt2, r);
                                }
                                // Direita
                                if(ingrid(ii, j+1)){
                                    int &nxt = dp[i][j+1][d][0][k];
                                    nxt = max(nxt, r);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    int ans = -INF;
    int fi = (n-1)&1;
    int fj = m-1;
    for(int d=0;d<2;d++){
        for(int bm=0;bm<(1<<4);bm++){
            for(int p=0;p<=k;p++){
                ans = max(ans, dp[fi][fj][d][bm][p]);
            }
        }
    }
    printf("%d\n", ans);
}

