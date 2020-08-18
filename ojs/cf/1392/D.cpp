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

const int MAXN = 212345;
const int INF = 0x3f3f3f3f;

int n, m, k;
char s[MAXN];

int dp[MAXN][2][2][2][2];

bool val(char c){
    return (c == 'R');
}

int go(int i, bool lstt, bool t, bool alst, bool fstt){
    int &r = dp[i][lstt][t][alst][fstt]; 
    if(r != -1) return r;
    int cus = (val(s[i]) != t);
    r = INF;
    if(i == 0){
        if(t == 0){
            r = min(r, cus + go(i+1, t, 0, 1, fstt)); // ult me ataca e prox me ataca
            r = min(r, cus + go(i+1, t, 1, 0, fstt)); // fodace ult, prox nao me ataca
            r = min(r, cus + go(i+1, t, 1, 1, fstt)); // fodace ult, prox nao me ataca
        }
        else{
            r = min(r, cus + go(i+1, t, 0, 1, fstt)); // ult me ataca e prox me ataca
            //r = min(r, cus + go(i+1, 1, 1));
            r = min(r, cus + go(i+1, t, 1, 0, fstt)); // prox n ataca, ult n ataca
            r = min(r, cus + go(i+1, t, 0, 0, fstt)); // prox ataca, ult n ataca
        }
        return r;
    }
    if(i == n-1){
        if(t != alst)
            return r = INF;
        else if((t == 0 && lstt == 0 && fstt == 0) || (t == 1 && lstt == 1 && fstt == 1))
            return r = INF;
        else
            return r = cus;
    }


    if(t == 0){
        if(lstt == 0){
            r = min(r, cus + go(i+1, t, 1, alst, fstt)); // prox n pode me atirar
        }
        else{
            r = min(r, cus + go(i+1, t, 0, alst, fstt)); 
            r = min(r, cus + go(i+1, t, 1, alst, fstt));
        }
    }
    else {
        if(lstt == 0){
            r = min(r, cus + go(i+1, t, 0, alst, fstt));
            r = min(r, cus + go(i+1, t, 1, alst, fstt));
        }
        else{
            r = min(r, cus + go(i+1, t, 0, alst, fstt));
        }
    }

    return r;
}

int main (){
    for_tests(t, tt){
        scanf("%d", &n);
        for(int a=0;a<=n;a++){
            for(int t1=0;t1<2;t1++){
                for(int t2=0;t2<2;t2++){
                    for(int t3=0;t3<2;t3++){
                        for(int t4=0;t4<2;t4++){
                            dp[a][t1][t2][t3][t4] = -1;
                        }
                    }
                }
            }
        }
        scanf(" %s", s);
        printf("%d\n", min(go(0, 0, 0, 0,0), go(0, 0, 1, 0, 1)));
    }
}

