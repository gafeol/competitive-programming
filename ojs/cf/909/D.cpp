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

const int MAXN = 1123456;

int n, m, k;
char s[MAXN];
char ch[MAXN];
int deg;

int qtd[MAXN];

int res;

int bef[MAXN], nxt[MAXN];

int rmv(){
	int mn = INT_MAX;
	int u = nxt[0];
	while(u != deg){
		debug("u %d qtd %d\n", u, qtd[u]);
		if(bef[u] == 0 || nxt[u] == deg)
			mn = min(qtd[u], mn);
		else
			mn = min(mn, (qtd[u] + 1)/2);
		u = nxt[u];
	}
	res += mn;
	debug("mn %d\n", mn);
	assert(mn != 0);
	u = nxt[0];
	while(u != deg){
		if(bef[u] == 0 || nxt[u] == deg)
			qtd[u] -= mn;
		else
			qtd[u] -= 2*mn;			
		qtd[u] = max(0, qtd[u]);
		debug("rmv %d qtd %d\n", u, qtd[u]);
		u = nxt[u];
	}
	u = nxt[0];
	while(u != deg){
		debug("sonda %d de qtd %d\n", u, qtd[u]);
		if(qtd[u] <= 0){
			int l = bef[u];
			int r = nxt[u];
			if(ch[l] != ch[r]){
				debug("tira %d l %d r %d\n", u, l, r);
				nxt[bef[u]] = nxt[u];
				bef[nxt[u]] = bef[u];
			}
			else{
				debug("iguais %d l %d r %d\n", u, l, r);
				qtd[l] += qtd[r];			
				nxt[l] = nxt[r];
				bef[nxt[l]] = l;
				nxt[u] = nxt[l];
			}
		}
		u = nxt[u];
	}
	if(nxt[0] == deg || nxt[nxt[0]] == deg)
		return 0;
	return 1;
}

int main (){
	scanf(" %s", s);
	n = strlen(s);
	int cnt = 1;
	int ult = 0;
	int fst = 1;
	deg = 1;
	for(int a=1;a<n;a++){
		if(s[a] != s[a-1]){
			qtd[deg] = cnt;
			if(fst)
				fst = 0;
			bef[deg] = ult;
			nxt[ult] = deg;
			ch[deg] = s[a-1];
			ult = deg;
			deg++;
			cnt = 0;
		}
		cnt++;
	}
	if(fst){
		printf("0\n");
		return 0;
	}
	debug("bota cnt %d deg %d\n", cnt, deg); 
	bef[deg] = ult;
	nxt[ult] = deg;
	nxt[deg] = deg+1;
	ch[deg] = s[n-1];
	qtd[deg] = cnt;
	deg++;
	bef[deg] = deg-1;
	nxt[deg] = deg;
	for(int a=0;a<=deg;a++){
		debug("deg %d ch %c bef %d nxt %d qtd %d\n", a, ch[a], bef[a], nxt[a], qtd[a]);
	}
	while(rmv());
	printf("%d\n", res);
}

