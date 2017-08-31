
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

ll gcd(ll a, ll b){
	if(b == 0) return a;
	return gcd(b, a%b);
}

struct rc{
	ll p, q;
	rc(ll pp, ll qq){
		p = pp;
		q = qq;
	}
	rc(){}
	rc operator + (rc o){
		rc a, r;
		a = rc(p*o.q, q*o.q);
		r = rc(a.p + o.p*q, a.q);
		ll g = gcd(r.p, r.q);
		rc res = rc(r.p/g, r.q/g);
		return res;
	}
	rc operator - (rc o){
		o.p = -o.p;
		rc a = rc(p, q);
		rc res = a+o; 
		return res;
	}
	bool operator < (const rc o) const{
		return (p*o.q < o.p*q);
	}
};

set<rc> q, aux;

vector<rc> d;

int main (){
	freopen("zanzibar.in", "r", stdin);
	scanf("%d", &n);
	for(int b=2;b<=13;b++){
		for(int a=1;a<b;a++){
			d.pb(rc(a, b));
		}
	}
	int cnt = 13;
	q.insert({0,1});
	while(cnt--){
		aux.clear();
		for(rc r: q){
			for(rc m: d){
				if((r + m) < rc(1, 1))
					aux.insert(r + m);
			}
		}
		for(auto &r: aux){
			q.insert(r);
		}
	}

	for(int a=0;a<n;a++){
		ll i, j;
		scanf("%lld %lld", &i, &j);
		rc l = rc(0, 1);
		if(q.lower_bound(rc(i, j)) != q.begin())
			l = *(--q.lower_bound(rc(i, j)));
		rc r = *q.lower_bound(rc(i, j));
		rc u = rc(i, j);
		rc mn = min(u-l, r-u);
		printf("Case %d: %lld/%lld\n", a+1, mn.p, mn.q); 
	}
}

