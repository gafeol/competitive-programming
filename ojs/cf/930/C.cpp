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
int s[MAXN];

struct arv{
	int lz, s;
} tree[MAXN*4];

void unlaze(int idx, int i, int j){
	int m = (i + j)/2;
	int aux = tree[idx].lz;
	tree[idx].lz = 0;
	if(i != j){
		tree[idx*2].s += (m - i + 1)*aux;
		tree[idx*2+1].s += (j - m)*aux;
		tree[idx*2].lz += aux;
		tree[idx*2+1].lz += aux;
	}
}

void upd(int idx, int i, int j, int l, int r){
	if(i > r || j < l) return ;
	unlaze(idx, i, j);
	if(i >= l && j <= r){
		tree[idx].s += (j - i + 1);
		tree[idx].lz++;
		return ;
	}
	int m = (i+j)/2;
	upd(idx*2, i, m, l, r);
	upd(idx*2+1,m+1, j, l, r);
}

int qry(int idx, int i, int j, int l){
	if(i > l || j < l) return 0;
	unlaze(idx, i, j);	
	if(i == j)
		return tree[idx].s;
	int m = (i+j)/2;
	return qry(idx*2, i, m, l) + qry(idx*2+1,m+1, j, l);
}

vector<int> lis;

inline int bb(int i, int j, int x){
	while(i < j){
		int m = (i+j+1)/2;
		if(lis[m] <= x)
			i = m;
		else
			j = m-1;
	}
	return i;
}

int res[MAXN][3], acu[MAXN][3];

int main (){
	scanf("%d%d", &n, &m);
	for(int a=0;a<n;a++){
		int i, j;
		scanf("%d %d", &i, &j);
		upd(1, 1, m, i, j);
	}
	for(int a=m;a>=1;a--){
		s[a] = qry(1, 1, m, a);
	}	

	//lis 
	lis.pb(INT_MIN);
	for(int a=1;a<=m;a++){
		int i = bb(0, lis.size()-1, s[a]);
		if(i + 1 == lis.size())
			lis.pb(s[a]);
		else
			lis[i+1] = s[a];
		res[a][0] = i+1;
	}
	lis.clear();
	lis.pb(INT_MIN);
	for(int a=m;a>=1;a--){
		int i = bb(0, lis.size()-1, s[a]);
		if(i + 1 == lis.size())
			lis.pb(s[a]);
		else
			lis[i+1] = s[a];
		res[a][1] = i+1;
	}
	for(int a=1;a<=m;a++){
		acu[a][0] = max(acu[a-1][0], res[a][0]);
	}
	for(int a=m;a>=1;a--)
		acu[a][1] = max(acu[a+1][1], res[a][1]);

	int ans = 0;
	for(int a=1;a<=m;a++){
		ans = max(ans, acu[a][0] + acu[a+1][1]);
	}
	printf("%d\n", ans);
}

