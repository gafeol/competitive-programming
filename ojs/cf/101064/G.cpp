#include <bits/stdc++.h>
using namespace std;
#define fst first
#define snd second
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;
#define pb push_back
#define for_tests(t, tt) int t; scanf("%d", &t); for(int tt = 1; tt <= t; tt++)
template<typename T> inline T abs(T t) { return t < 0? -t : t; }
const ll modn = 1000000007;
inline ll mod(ll x) { return x % modn; }

const int MAXN = 112345, LOGN = 25;

int n;

pii s[MAXN];

int p[MAXN][LOGN], v[MAXN];

int deg, h[MAXN];

int liga(int val, int pai){
	h[deg] = h[pai]+1;
	p[deg][0] = pai;
	for(int a=1;a<LOGN;a++){
		p[deg][a] = p[p[deg][a-1]][a-1];
	}
	v[deg] = val;
	deg++;
	return deg-1;
}

int paizao(int u, int v){
	if(h[u] < h[v])
		swap(u, v);
	
	for(int a=LOGN-1;a>=0;a--){
		if(h[p[u][a]] > h[v])
			u = p[u][a];
	}
	return u;
}

int main (){
	scanf("%d", &n);
	deg = 1;
	for(int a=1;a<=n;a++){
		char c;
		int va;
		scanf(" %c %d", &c, &va);
		if(c == 'E'){
			int x;
			scanf("%d", &x);
			s[a].fst = s[va].fst;
			s[a].snd = liga(x, s[va].snd);
			if(s[a].fst == 0)
				s[a].fst = s[a].snd;
			//printf("E %d %d: %d %d\n",  va, x, s[a].fst, s[a].snd); 
		}
		else{
			printf("%d\n", v[s[va].fst]);
			if(s[va].fst != s[va].snd){
				s[a].fst = paizao(s[va].fst, s[va].snd);
				s[a].snd = s[va].snd;
			}
			else{
				s[a].fst = 0;
				s[a].snd = 0;
			}
			//printf("%d %d\n", s[a].fst, s[a].snd);
		}
	}
}
