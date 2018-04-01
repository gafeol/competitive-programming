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

int n, m;
ll k;
ll s[MAXN], v[MAXN];



struct frac{
	ll p, q;

	frac(){
	}
	frac(ll a, ll b){
		p = a;
		q = b;
	}

};
bool operator<(const frac& t, const frac& o){ 
	return (t.p*o.q < t.q*o.p);
}

typedef pair<frac, pii> pfp;

vector<pfp> q;

int main (){
	scanf("%d%lld", &n, &k);
	for(int a=0;a<n;a++){
		scanf("%lld %lld", &s[a], v+a);
		int sig  = (s[a] < 0);
		s[a] = abs(s[a]);
		v[a] = abs(v[a]);
		frac mn = frac(s[a], v[a]+k);
		frac mx = frac(s[a], max(0ll, v[a]-k));
		if(!(mn < mx))
			swap(mn,mx);
		q.pb(pfp(mn, pii(0, sig)));
		q.pb(pfp(mx, pii(1, sig)));
	}
	sort(q.begin(), q.end());

	ll res = 0;
	ll cnt[2];
	cnt[0] = cnt[1] = 0;
	for(pfp it: q){
		pfp u = it;
		if(u.snd.fst == 0){
			res += cnt[1 - u.snd.snd];
			cnt[u.snd.snd]++;
		}
		else
			cnt[u.snd.snd]--;
	}
	printf("%lld\n", res);
}

