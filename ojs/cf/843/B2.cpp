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

const int MAXN = 212345, CNT  = 300, MX  = 1999;

int n, m, k;
pii s[MAXN];

void imp(){
	printf("! -1\n");
	fflush(stdout);
	exit(0);
}

void p(int x){
	printf("! %d\n", x);
	fflush(stdout);
	exit(0);
}

int main (){
	int st, x;
	scanf("%d %d %d", &n, &st, &x);
	for(int a=0;a<=n;a++){
		s[a] = pii(-1,-1);
	}
	int cnt = 0;
	int mx = n, mn = 1;
	int ult = -1, upp = INT_MAX;
	while(cnt < CNT && cnt < n){
		int i = st;
		while(s[i] != pii(-1, -1))
			i = mn + (rand() % static_cast<int>(mx - mn + 1));
		printf("? %d\n", i);
		fflush(stdout);
		int val, nxt;
		scanf("%d %d", &val, &nxt);
		if(val <= x && (ult == -1 || s[ult].fst < val))
			ult = i;
		if(val >= x)
			upp = min(val, upp);
		s[i] = pii(val, nxt);
		cnt++;
	}
	if(s[st].fst >= x)
		p(s[st].fst);
	pii u = s[ult];
	while(cnt < MX){
		if(u.fst >= x)
			p(u.fst);
		if(u.snd == -1)
			imp();
		printf("? %d\n", u.snd);
		fflush(stdout);
		int val, nxt;
		scanf("%d %d", &val, &nxt);
		u = pii(val, nxt);
		cnt++;
	}
	imp();
}

