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

double dp[11][11][11];
int tempo;
int mrk[11][11][11];

int n, br, ini;

double fat[55];

double ch(int i, int j){
    return fat[i]/(fat[i-j]*fat[j]);
}

double go(int meu, int seu, int amb){
    double &r = dp[meu][seu][amb];
    if(tempo == mrk[meu][seu][amb])
        return r;
    mrk[meu][seu][amb] = tempo;
    if(amb == 0 && (meu == 0 || seu == 0))
        return r = 0;
    double oldR = r;
    r = 0;
    for(int qmeu=0;qmeu<=meu && qmeu <= br;qmeu++){
        for(int qseu=0;qseu<=seu && qseu + qmeu <= br;qseu++){
            for(int qamb=0;qamb<=amb && qseu+qmeu+qamb <= br;qamb++){
                int qnin = br - qmeu - qseu - qamb; 
                if(qnin > n-meu-seu-amb) continue;
                double prob = ch(meu, qmeu)*ch(seu, qseu)*ch(amb, qamb)*ch(n-meu-seu-amb, qnin)/ch(n, br);
                if(qmeu == 0 && qseu == 0 && qamb == 0)
                    r += prob*(1 + oldR);
                else
                    r += prob*(1 + go(meu-qmeu, seu-qseu, amb-qamb));
            }
        }
    }
    return r;
}

int main (){
    clock_t clk = clock();
    fat[0] = 1;
    for(int i=1;i<=50;i++){
        fat[i] = i*fat[i-1];
    }
	scanf("%d%d%d", &n, &br, &ini);
    int soMeu, soSeu, deAmb;
    soMeu = soSeu = deAmb = 0;
    map<int, int> cnt;
    soMeu = ini;
	for(int a=0;a<ini;a++){
        int x;
        scanf("%d", &x);
        cnt[x]++;
	}
    for(int a=0;a<ini;a++){
        int x;
        scanf("%d", &x);
        if(cnt[x]){
            deAmb++;
            soMeu--;
        }
    }
    soSeu = ini - deAmb;

    while((clock() - (double)clk)/CLOCKS_PER_SEC < 1.1){
        tempo++;
        go(soSeu, soMeu, deAmb);
        /*
        for(int meu=soMeu;meu>=0;meu--){
            for(int seu=soSeu;seu>=0;seu--){
                for(int amb=deAmb;amb>=0;amb--){
                    go(meu, seu, amb); 
                }
            }
        }
        */
    }
    printf("%.10f\n", dp[soSeu][soMeu][deAmb]);
}

