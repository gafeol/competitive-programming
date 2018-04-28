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

multiset<int> q;

int mrk[MAXN];

int main (){
	scanf("%d", &n);
	for(int a=0;a<n;a++){
		scanf("%d", s+a);
		s[a]--;
	}
	for(int a=0;a<n;a++){
		if(!mrk[a]){
			int u = s[a];
			int sz = 1;
			mrk[a] = 1;
			while(u != a){
				sz++;
				mrk[u] = 1;
				u = s[u];	
			}
			q.insert(-sz);
		}
	}
	int u = *q.begin();
	q.erase(q.begin());
	if(q.empty()){
		printf("%lld\n", (ll)u*((ll)u));
		return 0;
	}
	u += *q.begin();
	q.erase(q.begin());
	ll ans = (ll)u*((ll)u);
	while(!q.empty()){
		ll aux = *q.begin();
		q.erase(q.begin());
		ans += aux*aux;
	}
	printf("%lld\n", ans);
}
