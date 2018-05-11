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

const int MAXN = 312345;

int n, m, k;
ll s[MAXN];
ll acu[MAXN];

int cnt[MAXN], mx[MAXN], remx[MAXN];
int ind[MAXN];
ll val[MAXN];

ll u, v;

bool cmp(int a, int b){
	return s[a] < s[b];
}

inline int qtd(ll x){
	return n - (lower_bound(s, s+n, x) - s);
}

int main (){
	scanf("%d%lld%lld", &n, &u, &v);
	for(int a=0;a<n;a++){
		scanf("%lld", s+a);
		ind[a] = a;
	}
	sort(ind, ind+n, cmp);
	sort(s, s+n);
	for(int a=0;a<n;a++){
		acu[a] = s[a];
		if(a > 0)
			acu[a] += acu[a-1];
	}
	for(ll a=1;a<=min((ll)n, v);a++){
		ll sob = (v + a-1)/a;
		val[a] = sob;
		cnt[a] = qtd(sob);
		mx[a] = cnt[a] - a;
		remx[a] = a;
		if(a > 0 && mx[a] < mx[a-1]){
			mx[a] = mx[a-1];
			remx[a] = remx[a-1];
		}
	}
	for(ll a = 1;a<=n;a++){
		if(a > 0 && mx[a] < mx[a-1]){
			mx[a] = mx[a-1];
			remx[a] = remx[a-1];
		}
	}
	for(ll a=1;a<=min((ll)n, u);a++){
		ll sob = (u + a-1)/a;
		int qt = qtd(sob);
		debug("a %lld sob %lld qt %d\n", a, sob, qt);
		if(qt < a) continue;	
		debug("mx[%lld] = %d\n", n-a, mx[n-a]);
		if(mx[n-a] >= a){
			puts("Yes");
			printf("%lld %d\n", a, remx[n-a]);
			int b = n-1;
			for(b=n-1;n-b<=a;b--)
				printf("%d ", ind[b]+1);
			puts("");
			for(int c =0;c<remx[n-a];c++)
				printf("%d ", ind[b-c]+1);
			puts("");
			return 0;
		}
	}

	//inverte
	swap(u, v);
	for(ll a=1;a<=min((ll)n, v);a++){
		ll sob = (v + a-1)/a;
		val[a] = sob;
		cnt[a] = qtd(sob);
		mx[a] = cnt[a] - a;
		remx[a] = a;
		if(a > 0 && mx[a] < mx[a-1]){
			mx[a] = mx[a-1];
			remx[a] = remx[a-1];
		}
	}
	for(ll a = 1;a<=n;a++){
		if(a > 0 && mx[a] < mx[a-1]){
			mx[a] = mx[a-1];
			remx[a] = remx[a-1];
		}
	}
	for(ll a=1;a<=min((ll)n, u);a++){
		ll sob = (u + a-1)/a;
		int qt = qtd(sob);
		debug("a %lld sob %lld qt %d\n", a, sob, qt);
		if(qt < a) continue;	
		debug("mx[%lld] = %d\n", n-a, mx[n-a]);
		if(mx[n-a] >= a){
			puts("Yes");
			printf("%d %lld\n", remx[n-a], a);
			int b = n-1;
			vector<int> aux;
			for(b=n-1;n-b<=a;b--)
				aux.pb(ind[b]+1);
			for(int c =0;c<remx[n-a];c++)
				printf("%d ", ind[b-c]+1);
			puts("");
			for(int i=0;i<aux.size();i++)
				printf("%d ", aux[i]);
			puts("");
			return 0;
		}
	}
	puts("No");
}
