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
ll s[MAXN], S;

multiset<ll> q;

void print(ll k){
	q.clear();
	for(int a=0;a<n;a++){
		q.insert(k*(a+1) + s[a]);
	}
	ll ans = 0;

	while(k--){
		ans += *q.begin();
		q.erase(q.begin());
	}
	printf("%lld\n", ans);
}

bool test(ll k){
	q.clear();
	for(ll a=0;a<n;a++){
		q.insert(k*(a+1) + s[a]);
	}
	ll ans = 0;

	while(k--){
		ans += *q.begin();
		q.erase(q.begin());
	}
	return (ans <= S);
}

int main (){
	scanf("%d %lld", &n, &S);
	for(int a=0;a<n;a++){
		scanf("%lld", &s[a]); 
	}
	int i = 0, j = n;
	while(i < j){
		int m = (i + j + 1)/2;
		if(test(m))
			i = m;
		else
			j = m-1;
	}
	printf("%d ", i); 
	print(i);
}
