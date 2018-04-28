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

const int MAXN = 21234;
const int MAXD = 212345;

int n, m, k;
int s[MAXN];

inline int num(char c){
	if(c >= '0' && c <= '9')
		return c - '0';
	return c -'A' + 10;
}

int p[MAXD], sz[MAXD];
int res;

int raiz(int u){
	if(p[u] == u) return u;
	return p[u] = raiz(p[u]);
}

void join(int u, int v){
	u = raiz(u);
	v = raiz(v);
	if(u == v) return;
	debug("join %d %d\n", u, v);
	res--;
	if(sz[u] < sz[v])
		swap(u, v);
	p[v] = u;
	sz[u] += sz[v];
}
int lst[MAXN], thi[MAXN], deg;

int main (){
	deg = 2;
	scanf("%d%d", &n, &m);
	for(int a=0;a<n;a++){
		for(int b=0;b<m/4;b++){
			char c;
			scanf(" %c", &c);
			int x = num(c);
			for(int i=3;i>=0;i--)
				if((1<<i)&x)
					thi[b*4+3-i] = 1;
				else
					thi[b*4+3-i] = 0;
		}
		for(int b=0;b<m;b++){
			if(lst[b] != 0 && thi[b] != 0){
				if(thi[b] != 1)
					join(lst[b], thi[b]);
				else
					thi[b] = lst[b];	
				int bb = b-1;
				while(bb >= 0 && thi[bb] != 0){
					if(thi[bb] == 1){
						thi[bb] = thi[b];
						sz[thi[bb]]++;
					}
					else{
						join(thi[bb], thi[b]);
						break;
					}
					bb--;
				}
				bb = b+1;
				while(bb < m && thi[bb] != 0){
					if(thi[bb] == 1){
						thi[bb] = thi[b];
						sz[thi[bb]]++;
					}
					else{
						join(thi[bb], thi[b]);
						break;
					}
					bb++;
				}
			}
		}
		for(int b=0;b<m;b++){
			lst[b] = thi[b];
			if(lst[b] == 1){
				if(b == 0 || lst[b-1] == 0){
					lst[b] = deg++;
					p[lst[b]] = lst[b];
					sz[lst[b]] = 1;
					res++;
				}
				else{
					lst[b] = lst[b-1];
					sz[lst[b]]++;
				}
			}
		}
	}
	printf("%d\n", res);
}
