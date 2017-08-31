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

const int MAXN = 212345, CNT  = 1500, MX  = 1999;

int n, m, k;
pii s[MAXN];

set<pii> q;

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
	int mx = 0;
	while(cnt < CNT && cnt < n){
		int i = st;
		while(s[i] != pii(-1, -1))
			i = 1 + (rand() % static_cast<int>(n - 1 + 1));
		printf("? %d\n", i);
		fflush(stdout);
		int val, nxt;
		scanf("%d %d", &val, &nxt);
		s[i] = pii(val, nxt); 
		q.insert(pii(val, i));
		cnt++;
	}
	if(s[st].fst >= x){
		p(s[st].fst);
		return 0;
	}
	pii lst = *(--q.lower_bound(pii(x, -1)));
	while(cnt < n && cnt < MX){
		if(lst.snd == -1)
			imp();
		printf("? %d\n", s[lst.snd].snd);	
		fflush(stdout);
		int val,nxt;
		scanf("%d %d", &val, &nxt);
		lst = pii(val, s[lst.snd].snd);
		s[s[lst.snd].snd] = pii(val,nxt);
		if(val >= x){
			printf("! %d\n", val);
			fflush(stdout);
			return 0;
		}
		cnt++;
	}
	if(q.lower_bound(pii(x, -1)) != q.end())
		printf("! %d\n", (q.lower_bound(pii(x, -1))->fst)); 
	else
		printf("! -1\n");
	fflush(stdout);
}

