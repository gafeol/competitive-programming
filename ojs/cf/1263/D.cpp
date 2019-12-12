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

int n, m, k;

int rep[MAXN];
int p[MAXN], sz[MAXN];

int raiz(int i){
    if(p[i] == i) return i;
    return p[i] = raiz(p[i]);
}

void join(int i, int j){
    if(min(i, j) == -1) return;
    i = raiz(i);
    j = raiz(j);
    if(i == j) return;
    if(sz[i] < sz[j])
        swap(i, j);
    p[j] = i;
    sz[i] += sz[j];
    k--;
}

int main (){
	scanf("%d", &n);
    k = n;
    memset(rep, -1, sizeof(rep));
	for(int a=0;a<n;a++){
        p[a] = a;
        sz[a] = 1;
        char s[MAXN];
        scanf(" %s", s);
        int tam = strlen(s);
        for(int i=0;i<tam;i++){
            join(a, rep[s[i]]);
            rep[s[i]] = a;
        }
	}
    printf("%d\n", k);
}

