#include <bits/stdc++.h>
using namespace std;
#define fst first
#define snd second
typedef unsigned long long ull;
typedef long long ll;
typedef pair<ll, ll> pii;
#define pb push_back
#define for_tests(t, tt) int t; scanf("%lld", &t); for(int tt = 1; tt <= t; tt++)
#ifndef ONLINE_JUDGE
#define debug(args...) fprintf(stderr,args)
#else
#define debug(args...)
#endif //ONLINE_JUDGE
template<typename T> inline T abs(T t) { return t < 0? -t : t; }
const ll modn = 1000000007;
inline ll mod(ll x) { return x % modn; }

#define int ll

const int MAXN = 212345;

int n, m, k;
int l, r;
int s[MAXN];

vector<pii> ev;

main (){
	int t = 0;
	while(t++ < 10){
		scanf("%lld%lld", &l, &r);
		l *= 2;
		r *= 2;
		if(l <= r){
			ev.pb(pii(l, 0));
			ev.pb(pii(r+1, 0));
		}
		scanf("%lld", &n);
		for(int a=0;a<n;a++){
			int i, j;
			scanf("%lld%lld", &i, &j);
			i *= 2ll;
			j *= 2ll;
			if(i <= j){
				ev.pb(pii(i, 1));
				ev.pb(pii(j+1ll, 2));
			}
		}
		sort(ev.begin(), ev.end());
		int on = 0, cnt = 0;
		int mx = LLONG_MIN;
		int mn = LLONG_MAX;
		for(int i =0;i<ev.size();i++){
			pii e = ev[i];
			if(e.snd == 0)
				on ^= 1;
			else if(e.snd == 1)
				cnt++;
			else
				cnt--;
			if(on && (i == ev.size()-1 || ev[i+1].fst != ev[i].fst)){
				mx = max(mx, cnt);
				mn = min(mn, cnt);
			}
		}
		if(mx == LLONG_MIN)
			mx = 0;
		if(mn == LLONG_MAX)
			mn = 0;
		printf("%lld %lld\n", mn, mx);
		ev.clear();
	}
}
