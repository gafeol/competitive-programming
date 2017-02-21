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

const int MAXN = 212345;

int n, m, k;
char s[MAXN], nd[MAXN];
int f[MAXN], mx[MAXN], mn[MAXN];
int res, tam;

void go(){ 	
	int i;
	i = 2;
	f[0] = 0;
	f[1] = 0;
	while(i <= tam){
		int ii = i-1;
		while(ii > 0 && nd[f[ii]+1] != nd[i])
			ii = f[ii];	

		if(nd[f[ii]+1] == nd[i]) f[i] = f[ii]+1;
		else f[i] = 0;

		debug("f[%d]: %d\n", i, f[i]);
		i++;
	}
	debug("sai\n");
}

void invs(){
	for(int i=1;i < n-i+1;i++)
		swap(s[i], s[n-i+1]);
}

void inv(){
	invs();
	for(int i=1;i < tam-i+1;i++)
		swap(nd[i], nd[tam-i+1]);
}

int main (){
	scanf(" %s", s+1);
	n = strlen(s+1);
	scanf("%d", &m);
	f[0] = 0;
	for(int a=0;a<m;a++){
		scanf(" %s", nd+1);	
		tam = strlen(nd+1);
		if(tam == 1) continue;
		go();
		mx[0] = 0;
		int b = 0;
		for(int a=1;a<=n;a++){
			while(b > 0 && s[a] != nd[b+1])
				b = f[b];
			if(s[a] == nd[b+1])
				b++;
			mx[a] = max(mx[a-1], b);
			debug("	mx[%d] %d\n", a, mx[a]);
		}
		inv();
		go();
		mn[n+1] = 0;
		b = 0;
		for(int a=1;a<=n;a++){
			while(b > 0 && s[a] != nd[b+1])
				b = f[b];
			if(s[a] == nd[b+1])
				b++;
			mn[n-a+1] = max(mn[n-a+2], b);
			debug("	mn[%d] = %d\n", n-a+1, mn[n-a+1]);
		}

		for(int a=0;a<=n;a++){
			if(mx[a] + mn[a+1] >= tam){
				res++;
				break;
			}
		}
		invs();
	}
	printf("%d\n", res);
}
