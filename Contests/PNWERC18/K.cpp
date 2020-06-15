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

const int MAXN = 212345;
const int BIT = (1<<9);

int n, m, k;
char s[MAXN];

double mxdp[BIT][10][10], mndp[BIT][10][10];

int sum(int bm){
    int ans = 0;
    for(int i=0;i<9;i++){
       ans += ((bm&(1<<i))>0)*(i+1);
    }
    return ans; 
}

double mngo(int bm, int d, int dd){
    double &r = mndp[bm][d][dd];
    if(r != -1)
        return r;
    //printf("bm %d d %d dd %d r %.3f\n", bm, d, dd, r);
    int cnt = 0;
    r = DBL_MAX;
    for(int p=0;p<(1<<9);p++){
        if((p&bm) != p || sum(p) != d + dd) continue;
        cnt++; 
        int nbm = (bm^p);
        double aux = 0;
        for(int i=1;i<=6;i++){
            for(int j=1;j<=6;j++){
                aux += mngo(nbm, i, j); 
            }
        }
        r = min(r, aux/36.);
    }
    if(!cnt){
        r = 0;
        for(int i=0;i<9;i++){
            if(bm&(1<<i)){
                r *= 10;
                r += i+1;
            }
        }
    }
    return r;
}

void mnre(int bm, int d, int dd){
    double &r = mndp[bm][d][dd];
    int cnt = 0;
    for(int p=0;p<(1<<9);p++){
        if((p&bm) != p || sum(p) != d + dd) continue;
        cnt++; 
        int nbm = (bm^p);
        double aux = 0;
        for(int i=1;i<=6;i++){
            for(int j=1;j<=6;j++){
                aux += mngo(nbm, i, j); 
            }
        }
        if(abs(r - aux/36.) < 1e-7){
            int valor = 0;
            for(int i=0;i<9;i++){
                if(p&(1<<i)){
                    valor *= 10;
                    valor += i+1;
                }
            }
            printf("%d ", valor);
            return ;
        }
    }
    if(!cnt)
        printf("-1 ");
}

double mxgo(int bm, int d, int dd){
    double &r = mxdp[bm][d][dd];
    if(r != -1)
        return r;
    //printf("bm %d d %d dd %d r %.3f\n", bm, d, dd, r);
    int cnt = 0;
    r = 0;
    for(int p=0;p<(1<<9);p++){
        if((p&bm) != p || sum(p) != d + dd) continue;
        cnt++; 
        int nbm = (bm^p);
        double aux = 0;
        for(int i=1;i<=6;i++){
            for(int j=1;j<=6;j++){
                aux += mxgo(nbm, i, j); 
            }
        }
        r = max(r, aux/36.);
    }
    if(!cnt){
        for(int i=0;i<9;i++){
            if(bm&(1<<i)){
                r *= 10;
                r += i+1;
            }
        }
    }
    return r;
}

void mxre(int bm, int d, int dd){
    double &r = mxdp[bm][d][dd];
    //printf("bm %d d %d dd %d r %.3f\n", bm, d, dd, r);
    int cnt = 0;
    for(int p=0;p<(1<<9);p++){
        if((p&bm) != p || sum(p) != d + dd) continue;
        cnt++; 
        int nbm = (bm^p);
        double aux = 0;
        for(int i=1;i<=6;i++){
            for(int j=1;j<=6;j++){
                aux += mxgo(nbm, i, j); 
            }
        }
        if(abs(r - aux/36.) < 1e-7){
            int valor = 0;
            for(int i=0;i<9;i++){
                if(p&(1<<i)){
                    valor *= 10;
                    valor += i+1;
                }
            }
            printf("%d ", valor);
            return ;
        }
    }
    if(!cnt)
        printf("-1 ");
}
int main (){
    for(int a=0;a<BIT;a++){
        for(int b=0;b<=6;b++){
            for(int c=0;c<=6;c++){
                mxdp[a][b][c] = mndp[a][b][c] = -1.;
            }
        }
    }
    int x, y;
	scanf(" %s %d%d", s, &x, &y);
    int n = strlen(s);
    int bm = 0;
    for(int a=0;a<n;a++){
        bm |= (1<<(s[a]-'1'));
    }
    mngo(bm, x, y);
    mnre(bm, x, y);
    printf("%.5f\n", mngo(bm, x, y));
    mxgo(bm, x, y);
    mxre(bm, x, y);
    printf("%.5f\n", mxgo(bm, x, y));
}

