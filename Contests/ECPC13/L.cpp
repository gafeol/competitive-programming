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

const int MAXN = 2*27*27 + 10, INF = 0x3f3f3f3f;

int n, m, k;
char s[MAXN];

int nxt[MAXN][30];

char next(char c, int i, int mul, int add){
	return ('a' + ((c - 'a')*mul + i*add)%26);
}

int main (){
	freopen("mahdi.in", "r", stdin);
	for_tests(t, tt){
		memset(nxt, INF, sizeof(nxt));
		char c;
		int T, mul, add;
		scanf(" %c %d %d %d", &c, &T, &mul, &add);
		mul = mul%26;
		add = add%26;
		int sz = min(T, 27*27 - 1);	
		s[0] = c;
		debug("str %c", c);
		for(int a=1;a<sz;a++){
			s[a] = next(s[a-1], a, mul, add); 
			debug("%c", s[a]);
		}
		debug("\n");
		for(int a=sz;a<=2*sz;a++){
			s[a] = s[a-sz];
		}
		for(int a=2*sz-1;a>=0;a--){
			for(int b=0;b<26;b++){
				nxt[a][b] = nxt[a+1][b];
			}
			nxt[a][s[a]-'a'] = a+1;
		}
		scanf("%d", &n);
		printf("Case %d:\n", tt); 
		for(int a=0;a<n;a++){
			int cnt = 0;
			int tam;
			scanf(" %c %d %d %d", &c, &tam, &mul, &add);
			debug("qry ");
			int i = 0, j = 0;
			while(i < tam && cnt < T){
				cnt += nxt[j][c-'a'] - j;	
				j = nxt[j][c-'a']%sz;
				debug("quero %c vou pra %d j\n", c, j);
				i++;
				debug("%c", c);
				c = next(c, i, mul, add);
			}
			debug("\n");
			if(i == tam && cnt <= T)
				puts("BRAVO");
			else
				puts("REPEAT");
		}
	}
}

