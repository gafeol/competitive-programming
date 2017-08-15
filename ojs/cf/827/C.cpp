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

const int MAXN = 112345, MAXB = 11*11*4;

int n, m, k;
char s[MAXN], st[11];
int cp[MAXN][11][11][4];
int bit[11*11*4][MAXN];

int subsz[11][11][4];


char ch[] = {'A', 'C', 'G', 'T'};

inline int ic(char c){
	for(int i=0;i<4;i++)
		if(ch[i] == c)
			return i;
	debug("ERRO char %c\n", c);
	return -1;
}

int ind[11][11][4], degi;

void upd(int idx, int i, int x){
	if(idx < 1) return ;
	i+=2;
	while(i < MAXN){
		bit[idx][i] += x;
		i += (i&-i);
	}
}

int qry(int idx, int i){
	if(idx < 1) return 0;
	i += 2;
	int ans = 0;
	while(i > 0){
		ans += bit[idx][i];
		i -= (i&-i);
	}
	return ans;
}

int main (){
	scanf(" %s", s);
	degi = 1;
	int tam = strlen(s);
	for(int sz=1;sz<=10 && sz <= tam;sz++){
		for(int c=0;c<4;c++){
			for(int ini=0;ini<sz && ini < tam;ini++){
				int deg = 0;
				debug("degi %d sub sz %d c %c ini %d SUBS ", degi, sz, ch[c], ini);
				for(int i=ini;i<tam;i+=sz){
					debug("%d", (int)(s[i] == ch[c]));
					if(s[i] == ch[c])
						upd(degi, deg, 1);
					cp[deg++][ini][sz][c] = (s[i] == ch[c]); 
				}
				debug("\n");
				subsz[ini][sz][c] = deg;
				ind[ini][sz][c] = degi;
				degi++;
			}
		}
	}
	scanf("%d", &n);
	for(int a=0;a<n;a++){
		int t;
		scanf("%d", &t);
		if(t == 2){
			int l, r;
			scanf("%d %d %s", &l, &r, st);
			l--;r--;
			int tam = strlen(st);
			int res = 0;
			debug("res += \n");
			for(int i=0;i<tam;i++){
				int idx = ind[(l + i)%tam][tam][ic(st[l+i])];
				printf("qry no degi %d entre %d e %d\n", idx, (l+i)/tam - ((l+i)%tam == 0), r/tam);
				res += qry(idx, r/tam) - qry(idx, (l+i)/tam - ((l+i)%tam == 0));
			}
			printf("%d\n", res);
		}
		else{
			int i;
			char c;
			scanf("%d %c", &i, &c);
			int l = ic(s[i]), r = ic(c);
			int idx;
			for(int sz = 1;sz <= 10 && sz <= tam;sz++){
				// tira
				idx = ind[i%sz][sz][l];
				upd(idx, i/tam, -1);
				// bota 
				idx = ind[i%sz][sz][r];
				upd(idx, i/tam, 1);
			}
		}
	}
}
