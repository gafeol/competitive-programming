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

const int MAXN = 215;

int n, m, k;
int s[MAXN][MAXN];
int mrk[MAXN];
int tempo;

int main (){
    for_tests(t, tt){
        tempo = 0;
        scanf("%d", &n);
        for(int a=0;a<=n;a++)
            mrk[a] = 0;
        int sum = 0;
        for(int a=0;a<n;a++){
            for(int b=0;b<n;b++){
                scanf("%d", &s[a][b]);
                if(a == b)
                    sum += s[a][b];
            }
        }
        int R = 0;
        for(int a=0;a<n;a++){
            tempo++;
            bool ok = false;
            for(int b=0;b<n;b++){
                if(mrk[s[a][b]] == tempo)
                    ok = true;
                mrk[s[a][b]] = tempo;
            }
            R += ok;
        }
        int C = 0;
        for(int b=0;b<n;b++){
            tempo++;
            bool ok = false;
            for(int a=0;a<n;a++){
                if(mrk[s[a][b]] == tempo)
                    ok = true;
                mrk[s[a][b]] = tempo;
            }
            C += ok;
        }
        printf("Case #%d: %d %d %d\n", tt, sum, R, C);
    }
}
