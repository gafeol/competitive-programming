#include <bits/stdc++.h>
using namespace std;
#define fst first
#define snd second
typedef unsigned long long ull;
typedef long long ll;
typedef pair<ll, ll> pii;
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
pii s[MAXN];
ll d, v, V;

set<pii> q;

void fail(){
	puts("-1");
	exit(0);
}

int main (){
	ll res = 0;
	scanf("%lld %lld %d", &d, &v, &n);
	V = v;
	for(int a=0;a<n;a++)
		scanf("%lld %lld", &s[a].fst, &s[a].snd);

	sort(s, s+n);
	s[n].fst = d;
	s[n].snd = INT_MAX;

	int i = 0, j = 0;
	ll up = v;
	while(i <= n && s[i].fst <= v){
		q.insert(pii(s[i].snd, s[i].fst));
		i++;
		debug("add %d\n", i);
	}
	ll ult = 0;
	while(j <= n){
		debug("j %d i %d\n", j, i);
		v -= s[j].fst - ult;
		if(v < 0){
			debug("fail %d %d %d %d\n", i, j, up, v);
			fail();
		}
		if(j == n)
			break;
		pii top = *q.begin();
		swap(top.fst, top.snd);
		while(i <= n && v < V && top == s[j]){
			debug("eh top i %d j %d\n", i, j);
			if(i <= n && v + s[i].fst - up <= V){
				res += s[j].snd * (s[i].fst - up);	
				v += s[i].fst - up;
				up = s[i].fst;
				q.insert(pii(s[i].snd, s[i].fst));
				i++;
			}
			else if(i <= n){
				res += s[j].snd *(V - v);
				up += V - v;
				v = V;
			}
			top = *q.begin();
			swap(top.fst, top.snd);
		}
		ult = s[j].fst;
		q.erase(pii(s[j].snd, s[j].fst));
		j++;
	}
	printf("%lld\n", res);
}

