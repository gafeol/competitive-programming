
#include <bits/stdc++.h>
using namespace std;
#define fst first
#define snd second
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;
#define pb push_back
#define for_tests(t, tt) int t; scanf("%d", &t); for(int tt = 1; tt <= t; tt++)
template<typename T> inline T abs(T t) { return t < 0? -t : t; }
const ll modn = 1000000007;
inline ll mod(ll x) { return x % modn; }

const int MAXN = 1000006, LOGN = 22;

int n, m;
int nxt[MAXN][LOGN];

int main (){
	scanf("%d%d", &n, &m);
    for(int k=0;k<LOGN;k++)
        for(int a=0;a<MAXN;a++)
            nxt[a][k] = a;
    for(int a=0;a<n;a++){
        int i, j;
        scanf("%d%d", &i, &j);
        nxt[i][0] = max(nxt[i][0], j);
    }
    for(int a=0;a<MAXN;a++)
        nxt[a][0] = max(nxt[a][0], (a > 0 ? nxt[a-1][0] : 0));

    for(int k=1;k<LOGN;k++){
        for(int a=0;a<MAXN;a++){
            if(nxt[a][k-1] == a)
                nxt[a][k] = a;
            else
                nxt[a][k] = nxt[nxt[a][k-1]][k-1];
            nxt[a][k] = max(nxt[a][k], (a > 0 ? nxt[a-1][k] : 0));
        }
    }
    for(int i=0;i<m;i++){
        int l, r;
        scanf("%d%d", &l, &r);

        int u = l;
        int stp = 0;
        for(int pot = LOGN-1;pot>=0;pot--){
            ///printf("u %d nxt[%d][%d] %d\n", u, u, pot, nxt[u][pot]);
            if(nxt[u][pot] < r){
                u = nxt[u][pot];
                stp += (1<<pot);
            }
        }
        u = nxt[u][0];
        stp++;
        if(u < r)
            puts("-1");
        else
            printf("%d\n", stp);
    }
}
