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

const int MAXN = 2123;

int n, m, k;
ll M[MAXN][MAXN];

int main (){
	scanf("%d", &n);
	for(int a=0;a<n;a++){
        for(int b=0;b < n;b++){
            scanf("%lld", &M[a][b]);
        }
	}
    long double aux = ((long double)sqrt(M[0][1]*M[1][2])*(long double)sqrt(M[2][0])+0.001);
    ll f = ((ll)aux)/M[1][2];
    printf("%lld", f);
    for(int a=1;a<n;a++){
        printf(" %lld", M[0][a]/f);
    }
}

