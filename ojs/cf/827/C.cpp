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

int sz[11][11][4];


char ch[] = {'A', 'C', 'G', 'T'};

inline int ic(char c){
	for(int i=0;i<4;i++)
		if(ch[i] == c)
			return i;
	puts("ERRO");
	return -1;
}

int ind[11][11][4], degi;

void upd(int idx, int i, int x){
	i+=2;
	while(i < MAXN){
		bit[idx][i] += x;
		i += (i&-i);
	}
}

int qry(int idx, int i){
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
	int tam = strlen(s);
	for(int sz=1;sz<=10;sz++){
		for(int c=0;c<4;c++){
			for(int ini=0;ini<sz;ini++){
				int deg = 0;
				for(int i=ini;i<tam;i+=sz){
					if(s[i] == ch[c])
						upd(degi, deg, 1);
					cp[deg++][ini][sz][c] = (s[i] == ch[c]); 
				}
				sz[ini][sz][c] = deg;
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
			for(int i=0;i<tam;i++){
				int idx = ind[(l + i)%tam][tam][ic(st[l+i])];
				res += qry(idx, r/tam) - qry(idx, (l+i)/tam - ((l+i)%tam == 0));
			}
		}
		else{
			scanf("%d %c", &i, &c);
			// fazer upd 1
			for(int tam = 1;tam <= 10;tam++){

				upd(
			}
		}
	}

}
