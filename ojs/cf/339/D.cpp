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

const int MAXN = (1<<18)+10;

int n, m, k;
ll s[MAXN];

ll tree[MAXN*4];
int pot[MAXN];

void build(int idx, int i, int j){
	if(i == j){
		tree[idx] = s[i];
		return ;
	}
	int m = (i + j)/2;
	build(idx*2, i, m);
	build(idx*2+1, m+1, j);
	if(pot[j - i + 1])
		tree[idx] = (tree[idx*2]^tree[idx*2+1]);
	else
		tree[idx] = (tree[idx*2]|tree[idx*2+1]);
}

void upd(int idx, int i, int j, int l, int x){
	if(i > l || j < l) return ;
	if(i == j){
		tree[idx] = x;
		return ;
	}
	int m = (i + j)/2;
	upd(idx*2, i, m, l, x);
	upd(idx*2+1, m+1, j, l, x);
	if(pot[j - i + 1])
		tree[idx] = (tree[idx*2]^tree[idx*2+1]);
	else
		tree[idx] = (tree[idx*2]|tree[idx*2+1]);
}


int main (){
	scanf("%d%d", &n, &m);
	ll tam = 2;
	pot[1] = 1;
	while(tam < MAXN){
		pot[tam] = (pot[tam/2]^1);
		tam *= 2ll;
	}

	n = (1<<n);
	for(int a=0;a<n;a++){
		scanf("%lld", s+a);
	}
	build(1, 0, n-1);
	for(int a=0;a<m;a++){
		int i, j;
		scanf("%d %d", &i, &j);
		i--;
		upd(1, 0, n-1, i, j);
		printf("%lld\n", tree[1]);
	}
}

