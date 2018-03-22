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

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define GNU __gnu_pbds

namespace GNU { typedef tree<int, null_type, less<int>, rb_tree_tag,
	tree_order_statistics_node_update> ordered_set; }
using GNU::ordered_set;
// null_type pode mudar pra virar map
// multiset e multimap nao tem suporte aqui, tem que sair usando pair pelo jeito
// less eh o comparador

// s.insert(int) s.erase(iterator ou int)
// end(s) == s.find_by_order(int) -> s nao contem int
// find_by_order retorna o iterator pro kth maior elemento (comecando do 0)
// 	(int) *s.find_by_order(int)
// order_of_key retorna o numero de elementos no set estritamente menor que int
// 	(int) s.order_of_key(int)


const int MAXN = 102345;

int n, m, k;
int s[MAXN];

ordered_set mult[MAXN], pos[MAXN];

vector<int> di[MAXN];


int qry(int i, int x){
	if(i < 0) return 0;
	return (int) pos[x].order_of_key(i+1);
}

int qrym(int i, int x){
	return (int) mult[x].order_of_key(i+1);
}

vector<int> pri;
vector<int> fp[MAXN];

void add(int a){
	int x = s[a];
	for(int bm = 1;bm < (1<<fp[x].size());bm++){
		int mul = 1;
		for(int i=0;i<fp[x].size();i++)
			if(((1<<i)&bm))
				mul *= fp[x][i];
		pos[mul].insert(a);
	}
}

void rmv(int a){
	int x = s[a];
	for(int bm = 1;bm < (1<<fp[x].size());bm++){
		int mul = 1;
		for(int i=0;i<fp[x].size();i++)
			if(((1<<i)&bm))
				mul *= fp[x][i];
		pos[mul].erase(a);
	}
}

int main (){
	scanf("%d", &n);
	for(int a=2;a<=100000;a++){
		if(!fp[a].empty()) continue;
		pri.pb(a);
		for(int b=1;a*b<=100000;b++){
			fp[a*b].pb(a);
		}
	}
	for(int x=2;x<=100000;x++){
		for(int a=1;x*a <= 100000;a++){
			di[x*a].pb(x);	
		}
	}

	for(int a=0;a<n;a++){
		scanf("%d", s+a);
		add(a);
	}
	scanf("%d", &m);
	for(int a=0;a<m;a++){
		int t;
		scanf("%d", &t);
		if(t-1){
			int l, r, x;
			scanf("%d %d %d", &l, &r, &x);
			l--;r--;
			debug("\n\nx %d\n", x);
			int res = r - l + 1;
			for(int bm = 1;bm < (1<<fp[x].size());bm++){
				int mul = 1;
				for(int i=0;i<fp[x].size();i++)
					if(((1<<i)&bm))
						mul *= fp[x][i];
				debug("div  ate r %d tem %d valores %d\n", r, qry(r, mul), mul);
				debug("div  ate l-1 %d tem %d valores %d\n", l-1, qry(l-1, mul), mul);
				debug("res += %d\n", (qry(r, mul) - qry(l-1, mul))*((-2)*(__builtin_popcount(bm)&1)+1)); 
				res += (qry(r, mul) - qry(l-1, mul))*((-2)*(__builtin_popcount(bm)&1)+1);
			}
			printf("%d\n", res);
		}
		else{
			int pos, val;
			scanf("%d %d", &pos, &val);
			pos--;
			int ult = s[pos];
			rmv(pos);
			s[pos] = val;
			add(pos);
		}
	}
}

