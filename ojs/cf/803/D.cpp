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

const int MAXN = 112345;

int n, m, k;
int s[MAXN], mrk[MAXN];

int main (){
	scanf("%d", &n);
	int tot = n;
	for(int a=0;a<n;a++){
		scanf("%d", s+a);
		mrk[s[a]]++;
	}
	sort(s, s+n);
	ll cnt = 0;
	ll res =0;
	for(int a=0;a<n;a++){
		mrk[s[a]]--;
		tot--;
		cnt = 1;
		while(a+1 < n && s[a+1] == s[a]){
			a++;
			mrk[s[a]]--;
			tot--;
			cnt++;
		}
		if(s[a] == 1){
			debug("s[a] %d res = %lld + %lld\n", s[a], res, ((1ll<<cnt)-1)*(1ll<<tot));
			res = mod(res + ((1ll<<(cnt))-1)*(1ll<<((ll)tot)));
			continue;
		}
		ll cnt2 = 0;
		for(int b=1;s[a]*b<MAXN;b++){
			cnt2 += mrk[s[a]*b];
		}
		cnt2 = tot - cnt2;
		debug("s[a] %d res = %lld + %lld\n", s[a], res, ((1ll<<cnt)-1)*((1ll<<cnt2)-1));
		res = mod(res + ((1ll<<cnt)-1)*((1ll<<cnt2)-1)); 
	}
	printf("%lld\n", res);
}
