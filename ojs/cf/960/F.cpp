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

const int MAXN = 112345;

int n, m, k;
int s[MAXN];

map<int, int> mnc[MAXN]; //[mx] = tam
set<int> cus[MAXN]; // mx 

inline int best(int u, int val){
	return *(--cus[u].lower_bound(val));
}

int ans;

inline void insere(int u, int mx, int tam){
	auto it = cus[u].lower_bound(mx);
	while(it != cus[u].end() && mnc[u][(*it)] <= tam){
		int val = *it;
		it++;
		mnc[u].erase(val);
		cus[u].erase(val);
	}
	it = --cus[u].lower_bound(mx);
	if(mnc[u][*it] >= tam) return ;
	cus[u].insert(mx);
	mnc[u][mx] = tam;
	ans = max(tam, ans);
}

int main (){
	ans = 0;
	scanf("%d%d", &n, &m);
	for(int a=1;a<=n;a++){
		mnc[a][-1] = 0;
		cus[a].insert(-1);
	}
	for(int a=0;a<m;a++){
		int u, v, c;
		scanf("%d %d %d", &u, &v, &c);
		int mx = best(u, c); //maior mx de u que seja < c
		insere(v, c, mnc[u][mx] + 1);
	}
	printf("%d\n", ans);
}

