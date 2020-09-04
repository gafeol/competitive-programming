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
int s[MAXN];
int sz[MAXN], p[MAXN];

int raiz(int i){
    if(p[i] == i) return i;
    return p[i] = raiz(p[i]);
}

void join(int i, int j){
    i = raiz(i);
    j = raiz(j);
    if(i == j) return;
    if(sz[i] < sz[j]) swap(i, j);
    p[j] = i;
    sz[i] += sz[j];
}

int main (){
	scanf("%d%d", &n, &m);
    for(int a=0;a<n;a++){
        p[a] = a;
        sz[a] = 1;
    }
    int mx = 1;
	for(int a=0;a<m;a++){
        int i, j;
        scanf("%d%d", &i, &j);
        i--;j--;
        join(i, j);
        mx = max(mx, sz[raiz(i)]);
	}
    printf("%d\n", mx);
}

