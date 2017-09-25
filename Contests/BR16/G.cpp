
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
inline ll mod(ll x) { return ((x % modn) + modn)%modn; }

const int MAXN = 512345;

int n, m, k;
char s[MAXN];

int pos[MAXN], p[MAXN];

ll h[MAXN][27], ph[27], pot[MAXN];

int main (){
	memset(pos, -1, sizeof(pos));
	scanf(" %s", s);
	int tam = strlen(s);
	for(int i=0;i<tam;i++){
		for(int a=0;a<26;a++){
			if(i == 0){
				h[i][a] = ((s[i] - 'a') == a);
				continue;
			}
			h[i][a] = mod(h[i-1][a]*2ll + ((s[i] - 'a') == a));
		}
	}
	scanf("%d", &n);
	pot[0] = 1;
	for(int a=1;a<max(n, tam)+1;a++){
		pot[a] = mod(pot[a-1]*2ll);
	}
	for(int a=0;a<n;a++){
		scanf("%d", &p[a]);
		p[a]--;
		pos[p[a]] = a;
	}
	for(int i=0;i<n;i++){
		for(int a=0;a<26;a++){
			ph[a] = mod(ph[a]*2ll + (p[i] == a));
		}
	}
	int ans = 0;
	for(int i=0;i<tam-n+1;i++){
		int ok = 1;
		debug("i %d\n", i);
		for(int a=0;a<26;a++){
			if(pos[a] == -1)
				continue;
			else{
				debug("	c %d\n", a);
				int j = i + pos[a];
				int l = s[j] - 'a';
				ll sub = 0;
				if(i > 0)
					sub = h[i-1][l];
				debug("	compara %lld == %lld - %lld*%lld\n",ph[a], h[i+n-1][l], pot[i], sub);
				ok = min(ok, (int)(mod(ph[a]) == mod(h[i+n-1][l] - pot[n]*sub)));
			}
			if(!ok) break;
		}
		ans+=ok;
		if(ok)
			debug("DEU CERTOOO %d\n", i);
	}
	printf("%d\n", ans);
}

