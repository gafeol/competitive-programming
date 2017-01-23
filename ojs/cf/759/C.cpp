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
#define debug(args...) //fprintf(stderr,args)
#else
#define debug(args...)
#endif //ONLINE_JUDGE
template<typename T> inline T abs(T t) { return t < 0? -t : t; }
const ll modn = 1000000007;
inline ll mod(ll x) { return x % modn; }

const int MAXN = 212345;

int n, m, k;
ll s[MAXN];
ll tree[MAXN*4];
ll mx[MAXN*4];
ll lz[MAXN*4];
ll sum = 0;

void print(int idx, int i, int j){
	debug("PRINT %d %d-%d\ntree %lld\nmx %lld\n", idx, i, j, tree[idx], mx[idx]);
	if(i == j)
		return;
	if(lz[idx] != 0){
		int aux = lz[idx];
		lz[idx] = 0;
		if(i != j){
			mx[idx*2] += aux;
			mx[idx*2+1] += aux;
			lz[idx*2] += aux;
			lz[idx*2+1] += aux;
		}
	}
	int m = (i+j)/2;
	print(idx*2, i, m);
	print(idx*2+1, m+1, j);
}

void upd(int idx, int i, int j, int l, ll val){
//	printf("ENTRA\nupd %d %d %d %d %lld sum %lld\n", idx, i, j, l, val, sum);
//	printf("mx %lld\ntree %lld\n", mx[idx], tree[idx]);
	if(l > j || l < i) return;
	if(lz[idx] != 0){
		int aux = lz[idx];
		lz[idx] = 0;
		if(i != j){
			mx[idx*2] += aux;
			mx[idx*2+1] += aux;
			lz[idx*2] += aux;
			lz[idx*2+1] += aux;
		}
	}
	if(i == j){
		tree[idx] += val;
		mx[idx] = sum + val;
		debug("i %d tree %lld mx %lld\n", i, val, sum + val);
		return ;
	}
	int m = (i+j)/2;
	upd(idx*2+1, m+1, j, l, val);
	sum += tree[idx*2+1];
	upd(idx*2, i, m, l, val);
	sum -= tree[idx*2+1];
	
	if(l > m){
		mx[idx*2] += val;
		lz[idx*2] += val;
	}

	tree[idx] = tree[idx*2] + tree[idx*2+1];
	mx[idx] = max(mx[idx*2], mx[idx*2+1]);
//	printf("SAI\nupd %d %d %d %d %lld sum %lld\n", idx, i, j, l, val, sum);
//	printf("mx %lld\ntree %lld\n", mx[idx], tree[idx]);
}


int qry(int idx, int i, int j){
	debug("qry(%d %d %d)\nmx %lld\ntree %lld\nsum %lld\n\n", idx, i, j, mx[idx], tree[idx], sum);
	if(mx[idx] <= 0) return -1;
	if(lz[idx] != 0){
		int aux = lz[idx];
		lz[idx] = 0;
		if(i != j){
			mx[idx*2] += aux;
			mx[idx*2+1] += aux;
			lz[idx*2] += aux;
			lz[idx*2+1] += aux;
		}
	}
	if(i == j){
		if(mx[idx] == 1)
			return i;
		else
			return -1;
	}
	int m = (i + j)/2;
	if(mx[idx*2+1] > 0){
		debug("go right\n");
		return qry(idx*2+1, m+1, j);
	}
	else{
		sum += tree[idx*2+1];
		debug("go left tree[%d]: %lld\n", idx*2+1, tree[idx*2+1]);
		return qry(idx*2, i, m);
	}
}

int main (){
	scanf("%d", &n);
	for(int a=0;a<n;a++){
		int i, t, x;
		scanf("%d %d", &i, &t);
		sum = 0;
		if(t){
			scanf("%d", &x);
			s[i] = x;
			upd(1, 1, n, i, 1);
		}
		else{
			upd(1, 1, n, i, -1);
		}
	//	print(1, 1, n);
		sum = 0;
		int res = qry(1, 1, n);
		if(res == -1)
			printf("-1\n");
		else
			printf("%lld\n", s[res]); 
	}
}
