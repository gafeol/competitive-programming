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

vector<vector<ull> > v;

ll s[MAXN];

int main (){
	scanf("%d", &n);
	vector<ull> aux;
	for(int a=0;a<n;a++){
		scanf("%lld", s+a);
		if(s[a] >= 128){
			aux.pb(ull(s[a]-128));
		}
		else{
			aux.pb(ull(s[a]));
			v.pb(aux);
			aux.clear();
		}
	}
	assert(aux.empty());
	for(int i=0;i<v.size();i++){
		ull aux = 0;
		int cnt = 0;
		for(ull x:v[i]){
			aux += (1ull<<(7ull*cnt))*x;
			cnt++;
		}
		ll res = aux/2ull;
		if((aux&1))
			res = -res - 1ll;
		printf("%lld\n", res);
	}
}
