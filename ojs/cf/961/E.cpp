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
int s[MAXN];

multiset<int> dep;

int bit[MAXN];

int qry(int i){
	debug("qry %d: ", i);
	i += 2;
	int ans = 0;
	while(i > 0){
		ans += bit[i];
		i -= (i&-i);
	}
	debug("%d\n", ans);
	return ans;
}

void upd(int i, int val){
	debug("upd %d %d\n", i, val);
	i+= 2;
	while(i < MAXN){
		bit[i] += val;
		i += (i&-i);
	}
}
int main (){
	scanf("%d", &n);
	set<pii> q;
	for(int a=0;a<n;a++){
		scanf("%d", s+a);
		s[a] = min(s[a], n);
		upd(a+1, 1);
		q.insert(pii(s[a], a));
	}
	ll res = 0;
	for(int a=0;a<n;a++){
		while(!q.empty() && q.begin()->fst <= a){
			upd(q.begin()->snd+1, -1);
			q.erase(q.begin());
		}
		if(s[a] > a)
			upd(a+1, -1);
			q.erase(pii(s[a], a));
		res += qry(s[a]);	
	}
	printf("%lld\n", res);
	
}

