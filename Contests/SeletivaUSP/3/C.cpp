#include <bits/stdc++.h>
using namespace std;
#define fst first
#define snd second
#define int ll
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;
#define pb push_back
#define for_tests(t, tt) int t; scanf("%lld", &t); for(int tt = 1; tt <= t; tt++)
#ifndef ONLINE_JUDGE
#define debug(args...) fprintf(stderr,args)
#else
#define debug(args...)
#endif //ONLINE_JUDGE
template<typename T> inline T abs(T t) { return t < 0? -t : t; }
const ll modn = 1000000007;
inline ll mod(ll x) { return x % modn; }

const int MAXN = 2123456;

int n, m, k;
int s[MAXN];
int mrk[MAXN];

map<int, vector<int> > ind[2];
map<int, int> pos[2];

void go(int u){
	mrk[u] =1;
	// go right 
	int val = u + s[u];
	//int i = pos[1][val]+1;
	int tam = ind[1][val].size(); 
	for(int i = 0;i < tam;i++){
		if(mrk[ind[1][val][i]] == 0){
			debug("de u %lld -> %lld\n", u+1, ind[1][val][i]+1);
			go(ind[1][val][i]);
		}
	}


	//go left 
	val = u - s[u];
//	i = pos[0][val]+1;
	tam = ind[0][val].size();
	for(int i = 0;i < tam;i++){
		if(mrk[ind[0][val][i]] == 0){
			debug("de u %lld -> %lld\n", u+1, ind[0][val][i]+1);
		go(ind[0][val][i]);
		}
	}
}

main (){
	while(scanf("%lld", &n) != EOF && n != 0){
		for(int a=0;a<n;a++){
			scanf("%lld", &s[a]);
//			pos[0][a] = ind[0][s[a] + a].size();
			ind[0][s[a] + a].pb(a);
//			pos[1][a] = ind[1][a - s[a]].size();
			ind[1][a - s[a]].pb(a);
		}
		go(0);
		for(int a=n-1;a>=0;a--){
			if(mrk[a]){
				printf("%lld\n", a);
				break;
			}
		}
		for(int a=0;a<n;a++){
			mrk[a] = 0;
//			pos[0][a] = 0;
//			pos[1][a] = 0;
			ind[0][s[a] + a].clear();
			ind[1][a - s[a]].clear();
		}
	}
}
