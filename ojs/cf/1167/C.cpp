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

const int MAXN = 512345;

int n, m, k;
int s[MAXN];
int pai[MAXN];
int sz[MAXN];

int raiz(int u){
    if(pai[u] == u) return u;
    return pai[u] = raiz(pai[u]);
}

void join(int i, int j){
    i = raiz(i);
    j = raiz(j);

    if(i == j) return ;

    if(sz[i] < sz[j]) swap(i, j);
             
    pai[j]  = i;
    sz[i] += sz[j];
}

int main (){
	scanf("%d%d", &n, &m);
    for(int a=0;a<=n;a++){
        pai[a] = a;
        sz[a] = 1;
    }
	for(int a=0;a<m;a++){
        int sz;
        scanf("%d", &sz);
        int fst = -1;
        for(int a=0;a<sz;a++){
            int x;
            scanf("%d", &x);
            if(fst == -1)
                fst = x;
            else
                join(x, fst);
        }
	}
    for(int a=1;a<=n;a++){
        printf("%d ", sz[raiz(a)]);
    }
    puts("");
}

