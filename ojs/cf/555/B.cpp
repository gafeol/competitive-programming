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
#define debug(args...) fprintf(stderr,args)
#else
#define debug(args...)
#endif //ONLINE_JUDGE
template<typename T> inline T abs(T t) { return t < 0? -t : t; }
const ll modn = 1000000007;
inline ll mod(ll x) { return x % modn; }

const int MAXN = 212345;

int n, m, k;
vector<pii> s;

vector<pii> p;
vector<pii> cnd[MAXN]; 

multiset<pii> q;

int res[MAXN];
	
int main (){
	memset(res, -1, sizeof(res));
	scanf("%d%d", &n, &m);
	ll ii, jj;
	for(int a=0;a<n;a++){
		ll i, j;
		scanf("%lld %lld", &i, &j);
		if(a != 0){
			p.pb(pii(i - jj, j - ii));
		}
		ii = i;
		jj = j;

	}
	n--;
	for(int a=0;a<m;a++){
		ll x;
		scanf("%lld", &x);
		s.pb(pii(x, (ll)a));
	}
	sort(s.begin(), s.end());
	for(int i=0;i<p.size();i++){
		int l = (lower_bound(s.begin(), s.end(), pii(p[i].fst, -1))  - s.begin());	
		int r = (lower_bound(s.begin(), s.end(), pii(p[i].snd+1, -1)) - s.begin()) - 1;
		cnd[l].pb(pii(i, 0));
		cnd[r+1].pb(pii(i, 1));
	}		
	//em q
	// pii(R, ind)
	for(int a=0;a<m;a++){
		for(pii x: cnd[a]){
			if(!x.snd)
				q.insert(pii(p[x.fst].snd, x.fst));
			else{
				if(res[x.fst] == -1){
					puts("No");
					return 0;
				}
			}
		}
		if(q.empty()) continue;
		pii top = *q.begin();
		int u = top.snd;
		res[u] = s[a].snd;
		q.erase(top);
	}
	for(pii x: cnd[m]){
		if(!x.snd)
			q.insert(pii(p[x.fst].snd, x.fst));
		else{
			if(res[x.fst] == -1){
				puts("No");
				return 0;
			}
		}
	}
	puts("Yes");
	for(int a=0;a<n;a++){
		printf("%d ", res[a]+1);
	}
}
