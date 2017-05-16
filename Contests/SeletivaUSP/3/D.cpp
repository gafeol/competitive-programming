#include <bits/stdc++.h>
using namespace std;
#define fst first
#define snd second
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<pii, int> ppi;
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

const int MAXN = 31, INF = 0x3f3f3f3f;

#define G 0
#define L 1

int n, M;
int s[MAXN], d[MAXN];
int cnt[MAXN];

vector<ppi> ares;

ppi mk(int a, int b, int c){
	return ppi(pii(a, b), c);
}

void add(int i, int j, int t, int val){
	if(t == G)
		ares.pb(mk(j, i, -val));	
	else
		ares.pb(mk(i, j, val));
}

bool bellman(){
	memset(d, INF, sizeof(d));
	d[0] = 0;
	for(int it=0;it < 30;it++){
		for(ppi r : ares){
			int i = r.fst.fst;
			int j = r.fst.snd;
			int c = r.snd;
			if(d[j] > d[i] + c){
				d[j] = d[i] + c;
			}
		}
	}

	for(ppi r : ares){
		int i = r.fst.fst;
		int j = r.fst.snd;
		int c = r.snd;
		if(d[j] > d[i] + c){
			d[j] = d[i] + c;
			return false;
		}
	}
	return true;
}

bool go(int k){
	add(0, 24, G, k);
	add(0, 24, L, k);
	for(int a=1;a<=24;a++){
		if(a < 8)
			add(16+a, a, G, -k + s[a]);
		else
			add(a-8, a, G, s[a]);
	}
	bool ans = bellman();
	ares.pop_back();
	ares.pop_back();
	for(int a=1;a<=24;a++){
		ares.pop_back();
	}
	return ans;
}

void prep(){
	for(int i = 1;i <= 24;i++){
		add(i-1, i, L, cnt[i]);
		add(i-1, i, G, 0);
	}
}

int main (){
	for_tests(t, tt){
		ares.clear();
		for(int a=0;a<=24;a++){
			cnt[a] = 0;
			s[a] = 0;
		}
		for(int a=1;a<=24;a++){
			scanf("%d", s+a);
		}
		scanf("%d", &M);
		for(int a=0;a<M;a++){
			int val;
			scanf("%d", &val);
			val++;
			cnt[val]++;
		}
		prep();
		int i = 0, j = M;
		while(i < j){
			//debug("i %d j %d\n", i, j);
			int m = (i + j)/2;
			if(go(m))
				j = m;
			else
				i = m+1;
		}

		if(go(i))
			printf("%d\n", i);
		else
			printf("No Solution\n");
	}
}
