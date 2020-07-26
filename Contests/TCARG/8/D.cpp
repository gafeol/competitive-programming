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

const int MAXN = 1123456;

int n, m, k;
int s[MAXN];
int p[MAXN], sz[MAXN];

int raiz(int u){
    if(p[u] == u) return u;
    return p[u] = raiz(p[u]);
}

void join(int i, int j){
    i = raiz(i);
    j = raiz(j);
    if(i == j) return ;

    if(sz[i] < sz[j]) swap(i, j);
    
    p[j] = i;
    sz[i] += sz[j];
}

set<int> q[MAXN];

int main (){
	scanf("%d%d", &n,&m);
	for(int a=0;a<n;a++){
        scanf("%d", s+a);
        p[a] = a;
        sz[a] =1;
	}
    for(int a=0;a<m;a++){
        int i,j;
        scanf("%d%d", &i, &j);
        i--;j--;
        join(i, j);
    }
    for(int a=0;a<n;a++){
        q[raiz(a)].insert(-s[a]);
    }
    for(int a=0;a<n;a++){
        printf("%d%c", -*q[raiz(a)].begin(), " \n"[a==n-1]);
        q[raiz(a)].erase(q[raiz(a)].begin());
    }
}

