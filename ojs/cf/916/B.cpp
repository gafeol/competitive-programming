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

int m, k;
ll n;
int s[MAXN];

const int LOGN = 60;

map<int, int> cnt;

int main (){
	scanf("%lld %d", &n, &k);
	multiset<ll> q;
	ll mx = INT_MIN;
	for(ll i = LOGN;i>=0;i--){
		if((1ll<<i) > n) continue;
		n -= (1ll<<i);
		q.insert(-i);
		cnt[-i]++;
		mx = max(-i, mx);
	}
	if(q.size() > k){
		puts("No");
		return 0;
	}
	while(q.size() < k){
		ll top = *q.begin();
		if(cnt[top] > k-q.size()){
			debug("quero diminuir %lld mas so tenho %d livres\n", -top, k-(int)q.size());
			break;
		}
		q.erase(q.begin());
		q.insert(top+1);
		q.insert(top+1);
		cnt[top+1]+=2;
		cnt[top]--;
		mx = max(mx, top+1);
	}
	while(q.size() < k){
		q.erase(q.find(mx));		
		q.insert(mx+1);
		q.insert(mx+1);
		mx = mx+1;
	}
	puts("Yes");
	for(auto i: q){
		printf("%lld ", -i); 
	}
}

