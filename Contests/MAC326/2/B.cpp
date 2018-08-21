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

const int MAXN = 2123456;

int n, m, k;
char s[MAXN];
int q[MAXN];
char pal[MAXN];

vector<int> pos[30];

int mrk[MAXN];

int res[MAXN];

int main (){
	scanf("%d%d", &n, &m);
	scanf(" %s", pal);
	int tam = strlen(pal);
	ll palhash = 0;
	for(int a=0;a<tam;a++){
		palhash = mod(palhash*26ll);
		palhash = mod(palhash + pal[a] - 'a');
	}
	for(int a=0;a<m;a++){
		scanf("%d", &q[a]);
		q[a]--;
		mrk[q[a]] = 1;
	}
	int ind = -1;
	int ans = 0;
	for(int a=0;a<n;a++){
		if(mrk[a])
			ind = 0;
		else{
			ind++;
			if(ind == 0 || ind > tam) 
				ind = -1;
		}
		if(ind > 0)
			res[a] = pal[ind];
		else
			ans++;
	}
	for(int a=0;a<n;a++){
		printf("%c", res[a]);
	}
	puts("");
	ll hash = 0;
	ll pot = 1;
	debug("palhash %lld\n", palhash);
	for(int a=0;a<tam;a++)
		pot = mod(pot*26ll);
	for(int a=0;a<tam;a++){
		hash = mod(hash*26ll);
		hash = mod(hash + pal[a] - 'a');
	}
	for(int a=0;a<n-tam;a++){
		debug("a %d hash %lld\n", a, hash);
		if(mrk[a] && hash != palhash){
			puts("0");
			return 0;
		}
		hash = mod(modn + hash - pal[a]*pot);
		hash = mod(hash*26 + pal[a+tam]);
	}
	ll val = 1;
	for(int a=0;a<ans;a++){
		val = mod(val*26);	
	}
	printf("%lld\n", val);
}
