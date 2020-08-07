
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

const int MAXN = 112345;
const int N = 112345; typedef int num;
num X[N]; int en = 1, Y[N], sz[N], L[N], R[N], inv[N];
void calc (int u) { // update node given children info
	sz[u] = sz[L[u]] + 1 + sz[R[u]];
	// code here, no recursion
}

void unlaze (int u) {
	if(!u) return;
	// code here, no recursion
    if(inv[u]){
        X[u] = 1 - X[u];
        swap(L[u], R[u]);
        inv[u] = 0;
        inv[L[u]] ^= 1;
        inv[R[u]] ^= 1;
    }
}

void split_sz(int u, int s, int &l, int &r) { // l gets first s, r gets remaining
	unlaze(u); if(!u) return (void) (l = r = 0);
	if(sz[L[u]] < s) { split_sz(R[u], s - sz[L[u]] - 1, l, r); R[u] = l; l = u; }
	else { split_sz(L[u], s, l, r); L[u] = r; r = u; }
	calc(u);
}

int merge(int l, int r) { // els on l <= els on r
	unlaze(l); unlaze(r); if(!l || !r) return l + r; int u;
	if(Y[l] > Y[r]) { R[l] = merge(R[l], r); u = l; }
	else { L[r] = merge(l, L[r]); u = r; }
	calc(u); return u;
}
void init(int n=N-1) { // call before using other funcs
	for(int i = en = 1; i <= n; i++) { Y[i] = i; sz[i] = 1; L[i] = R[i] = inv[i] = 0; }
	random_shuffle(Y + 1, Y + n + 1);
}

int n, m, k;
char s[MAXN], obj[MAXN];

int main (){
    for_tests(t, tt){
        scanf("%d", &n);
        init(n+1);
        int root = 0;
        scanf(" %s", s);
        scanf(" %s", obj);
        vector<int> ans;

        int i = 0, j = n-1;
        int d = -1;
        int inv = 0;
        for(int a=n-1;a>=0;a--){
            if(obj[a]-'0' == ((s[j]-'0')^inv)){
                j += d;
                continue;
            }
            if(obj[a]-'0' == ((s[i]-'0')^inv)){
                s[i] = '0' + (1 - (s[i]-'0'));
                ans.pb(1);
            }
            swap(i, j);
            d *= -1;
            inv ^= 1;
            j += d;
            ans.pb(a+1);
        }
        printf("%d ", (int)ans.size());
        for(int x: ans){
            printf("%d ", x);
        }
        puts("");
    }
}
