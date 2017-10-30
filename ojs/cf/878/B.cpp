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

ll n, m, k;
ll s[MAXN];

ll res = 0;

ll cnt[MAXN];

vector<ll> ns;

int main (){
	scanf("%lld%lld%lld", &n, &k, &m);
	int eq = 1;
	for(int a=0;a<n;a++){
		scanf("%lld", &s[a]);	
		if(s[a] != s[0])
			eq = 0;
	}
	if(eq){
		printf("%lld\n", (n*m)%k);
		return 0;
	}
	ll j = 0;
	while(j < k){
		cnt[s[j]]++;
		j++;
	}
	for(ll i=0;i<n;i++){
		debug("i %d cnt[%d] %d\n", i, s[i], cnt[s[i]]);
		if(cnt[s[i]] == k){
			debug("peguei %d em %lld\n", s[i], i);
			res += m;
			while(cnt[s[i]] != 1){
				cnt[s[i]]--;
				i++;
			}
		}
		else
			ns.pb(s[i]);
		debug("tira %d\n", s[i]);
		cnt[s[i]]--;
		while(j < i + 1 + k && j < n){
			cnt[s[j]]++;
			j++;
			debug("bota s[%d]  %d\n", j, s[j]);
		}
	}
	debug("ns\n");
	for(ll x: ns){
		debug("%d ", x);
	}
	debug("\n");
	ll i = 0;
	j = ns.size()-1;
	ll cnt = 2;
	while(i < j && ns[i] == ns[j]){
		if(cnt == k){
			debug("pega entre %d %d res += %d\n", i, j, m-1);
			res += m - 1;
			i++;
			j--;
			cnt = 2;
		}
		else{
			cnt++;
			if(ns[i+1] == ns[i])
				i++;
			else if(ns[j-1] == ns[j])
				j--;
			else
				break;
		}
	}
	if(i == j){
		debug("sobrou um no meio %d res += %d\n", s[i], m/k);
		res += m/k;
		if(m%k == 0){
			ll ii = i-1;
			ll jj = j+1;
			ll cnt = 2;
			while(ii >= 0 && jj < ns.size() && ns[ii] == ns[jj]){
				if(cnt == k){
					res++;
					ii--;
					jj++;
					cnt = 2;
					continue;
				}
				if(ii > 0 && ns[ii] == ns[ii-1]){
					ii--;
					cnt++;
				}
				else if(jj < ns.size()-1 && ns[jj] == ns[jj+1]){
					jj++;
					cnt++;
				}
				else{
					break;
				}
			}
		}
	}
	printf("%lld\n", n*m - res*k);
}

