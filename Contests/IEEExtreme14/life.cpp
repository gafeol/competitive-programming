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

int n, m, k;
char s[2][6];

int M[30][30];
int aux[30][30];

int main (){
    scanf(" %[^;]", s[0]);
    getchar();
    scanf(" %[^\n]", s[1]);
    scanf("%d%d", &n, &k);
    for(int a=0;a<n;a++){
        for(int b=0;b<n;b++){
            char c;
            scanf(" %c", &c);
            M[a][b] = (c=='1');
        }
    }
    int vi[] = {1, 0, -1, 0};
    int vj[] = {0, 1, 0, -1};
    while(k--){
        for(int a=0;a<n;a++){
            for(int b=0;b<n;b++){
                int cnt = 0;
                for(int d=0;d<4;d++){
                    int na = (a + vi[d] + n)%n;
                    int nb = (b + vj[d] + n)%n;
                    cnt += M[na][nb];
                }
                aux[a][b] = (s[M[a][b]][cnt] == '1');
            }
        }
        for(int a=0;a<n;a++){
            for(int b=0;b<n;b++){
                M[a][b] = aux[a][b];
                aux[a][b] = 0;
            }
        }
    }
    for(int a=0;a<n;a++){
        for(int b=0;b<n;b++){
            printf("%d", M[a][b]);
        }
        puts("");
    }
    return 0;
}

