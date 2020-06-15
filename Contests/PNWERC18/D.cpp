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
const ll modn = 1000000009;
inline ll mod(ll x) { return x % modn; }

const int MAXN = 1123;
const int BIT = 130;

int n, m, k;
int s[MAXN];

ll qtd[MAXN][BIT];
ll sb[MAXN][BIT];

int main (){
	scanf("%d%d", &n, &k);
    qtd[0][0] = 1;
    for(int b=0;b<k;b++){
        for(int i=0;i<n;i++){
            int nxt = (i*2)%n;
            qtd[nxt][b+1] = mod(qtd[nxt][b+1] + qtd[i][b]);
            sb[nxt][b+1] = mod(sb[nxt][b+1] + sb[i][b]);
            nxt = (nxt+1)%n;
            qtd[nxt][b+1] = mod(qtd[nxt][b+1] + qtd[i][b]);
            sb[nxt][b+1] = mod(sb[nxt][b+1] + sb[i][b] + qtd[i][b]);
        }
    }
    printf("%lld\n", sb[0][k]);
}

