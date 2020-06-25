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

int n, m, k;
ll A[MAXN];
ll B[MAXN];
int ind[MAXN];
int p[MAXN], sz[MAXN];

int raiz(int u){
    if(p[u] == u) return u;
    return p[u] = raiz(p[u]);
}

int join(int u, int v){
    u = raiz(u);
    v = raiz(v);
    if(u == v) return false;
    if(sz[u] < sz[v])
        swap(u, v);
    p[v] = u;
    sz[u] += sz[v];
    return true;
}

bool cmp(int a, int b){
    return A[a]*B[b] > A[b]*B[a];
}

int main (){
    for_tests(t, tt){
        scanf("%d%d", &n, &m);
        for(int a=0;a<n;a++){
            ind[a] = a;
            p[a] = a;
            sz[a] = 1;
            scanf("%lld", A+a); }
        for(int a=0;a<n;a++){
            scanf("%lld", B+a); }
        sort(ind, ind+n, cmp);
        int mrk[MAXN];
        for(int a=0;a<n;a++){
            if(!cmp(ind[0], a))
                mrk[a] = true;
            else
                mrk[a] = false;
        }
        for(int a=0;a<m;a++){
            int u, v;    
            scanf("%d%d", &u, &v);
            u--;
            v--;
            if(mrk[u] && mrk[v])
                join(u, v);
        }

        int bst = 0, szbst = 0;
        for(int a=0;a<n;a++){
            if(!mrk[a]) continue;
            if(szbst < sz[raiz(a)]){
                szbst = sz[raiz(a)];
                bst = raiz(a);
            }
        }
        printf("%d\n", szbst);
        for(int a=0;a<n;a++){
            if(raiz(a) == bst)
                printf("%d ", a+1);
        }
        puts("");
    }
}

