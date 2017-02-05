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
char s[MAXN];

vector<ll> u, p, v;

int main (){
	scanf("%d%d %d", &n, &m, &k);
	int t;
	scanf("%d", &t);
	for(int a=0;a<t;a++){
		ll x;
		scanf("%lld %s", &x, s);
		if(s[0] == 'U')
			u.pb(x);
		else
			p.pb(x);
	}
	sort(u.begin(), u.end());
	sort(p.begin(), p.end());
	int i = 0, j = 0;
	ll sum = 0;
	int res = 0;
	while(n-- && i < u.size()){
		sum += u[i];
		res++;
		i++;
	}
	while(m-- && j < p.size()){
		sum += p[j];
		res++;
		j++;
	}
	while(i < u.size())
		v.pb(u[i++]);
	while(j < p.size())
		v.pb(p[j++]);
	sort(v.begin(), v.end());
	int a = 0;
	while(k-- && a < v.size()){
		res++;
		sum += v[a];
		a++;
	}
	printf("%d %lld\n", res, sum);
}
