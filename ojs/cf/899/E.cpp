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

set<pii> qtd, v;

int main (){
	scanf("%d", &n);
	int ult = 0;
	for(int a=0;a<n;a++){
		scanf("%d", s+a);
		if(s[ult] != s[a]){
			qtd.insert(pii(ult - a, ult));
			debug("insere %d %d\n", ult-a, ult);
			v.insert(pii(ult, a - ult));
			ult = a;
		}
	}
	int a = n;
	qtd.insert(pii(ult - a, ult));
	debug("insere %d %d\n", ult-a, ult);
	v.insert(pii(ult, a - ult));
	int res =0; 
	while(!qtd.empty()){
		res++;
		pii top = *qtd.begin();
		qtd.erase(top);
		int cnt = -top.fst;
		int pos = top.snd;
		debug("tira %d %d\n", -cnt, pos);
		pii inv = pii(pos, cnt);
		auto it = v.lower_bound(inv);
		auto bef = it;
		auto aft = it;
		aft++;
		if(it != v.begin() && aft != v.end()){
			bef--;
			if(s[bef->fst] == s[aft->fst]){
				qtd.erase(pii(-bef->snd, bef->fst));
				debug("erase %d %d\n", -bef->snd, bef->fst);
				qtd.erase(pii(-aft->snd, aft->fst));
				int nc = bef->snd + aft->snd;
				debug("erase %d %d\n", -aft->snd, aft->fst);
				int np = bef->fst;
				v.erase(bef);
				v.erase(aft);
				v.insert(pii(np, nc));
				qtd.insert(pii(-nc, np));
				debug("insere %d %d\n", -nc, np);
			}
		}
		v.erase(inv);
	}
	printf("%d\n", res);
}

