#include <bits/stdc++.h>
using namespace std;
#define fst first
#define snd second
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, ll> pil;
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

const int MAXN = 2123456;

const ll INF = 300000000000LL;

int n, m, k;
ll s[MAXN];

multiset<ll> bef[MAXN], aft[MAXN];
int ind[MAXN];

int d[MAXN], ini[MAXN], fim[MAXN];

vector<pil> in[MAXN], out[MAXN];

bool cmp(int a, int b){
	return d[a] < d[b];
}

ll sum;

void add(int i, int j, ll x){
	if(i == 0){
		sum -= *aft[j].begin();
		aft[j].insert(x);
		sum += *aft[j].begin();
	}
	else{
		sum -= *bef[i].begin();
		bef[i].insert(x);
		sum += *bef[i].begin();
	}
}

void rmv(int i, int j, ll x){
	if(i == 0){
		sum -= *aft[j].begin();
		aft[j].erase(aft[j].find(x));
		sum += *aft[j].begin();
	}
	else{
		sum -= *bef[i].begin();
		bef[i].erase(bef[i].find(x));
		sum += *bef[i].begin();
	}
}

int main (){
	scanf("%d%d%d", &n, &m, &k);
	for(int a=1;a<=n;a++){
		bef[a].insert(INF);
		aft[a].insert(INF);
		sum += 2ll*INF; 
	}
	for(int a=0;a<m;a++){
		scanf("%d%d%d%lld", &d[a], ini+a, fim+a, s+a);
		if(ini[a] == 0)
			out[d[a]].pb(pil(fim[a], s[a]));
		else
			in[d[a]].pb(pil(ini[a], s[a]));
	}
	for(int dia = 1000000;dia>=k;dia--){
		for(int i=0;i<out[dia].size();i++){
			pil voo = out[dia][i];
			add(0, voo.fst, voo.snd);
		}
	}
	ll res = LLONG_MAX;
	for(int dia = 0;dia <= 1000000-k;dia++){
		res = min(res, sum);
		for(pil voo: in[dia])
			add(voo.fst, 0, voo.snd);
		for(pil voo: out[dia+k])
			rmv(0, voo.fst, voo.snd);
	}
	if(res >= INF)
		puts("-1");
	else
		printf("%lld\n", res);
}
