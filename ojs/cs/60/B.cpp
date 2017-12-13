
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

const int MAXN = 212345;

int n, m, k;

int e1, e2;
int res;

pii s[MAXN];
int mrk[MAXN];

void marca(int l, int r){
	int t = (l <= r);
	int mn = min(l, r);
	int mx = max(l, r);
	for(int a=0;a<n;a++){
		if(t != (s[a].fst < s[a].snd)) continue;
		if(mx >= s[a].fst && mx >= s[a].snd && mn <= s[a].fst && mn <= s[a].snd){
			mrk[a] = 1;
		}
	}
}

int main (){
	scanf("%d %d %d", &n, &e1, &e2);
	for(int a=0;a<n;a++){
		int i, j;
		scanf("%d %d", &i, &j);
		s[a] = pii(i, j);
	}
	int ans = 0;
	for(int a=0;a<4;a++){
		res =0;
		memset(mrk, 0, sizeof(mrk)); 
		int l = e1, r;
		debug("e1\n");
		if((a&1))
			r = 1;
		else
			r = n;
		marca(l, r);
		l = e2;
		debug("e2\n");
		if((a&2))
			r = 1;
		else
			r = n;
		marca(l, r);
		for(int i=0;i<n;i++){
			if(mrk[i])
				debug("pega %d\n", i);
			res += mrk[i];
		}
		ans = max(ans, res);
	}
	printf("%d\n", ans);
}

