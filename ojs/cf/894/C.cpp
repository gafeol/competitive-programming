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
ll s[MAXN];

map<ll, int> ind;

vector<ll> ans;

ll gcd(ll a, ll b){
	if(b == 0) return a;
	return gcd(b, a%b);
}

int main (){
	scanf("%d", &n);
	int ok = 1;
	for(int a=0;a<n;a++){
		scanf("%lld", s+a);
		ind[s[a]] = 1;
		if(ind.find(gcd(s[a], s[0])) == ind.end())
			ok = 0;
	}
	if(!ok){
		puts("-1");
		return 0;
	}
	printf("%d\n", 2*n);
	for(int a=0;a<n;a++){
		printf("%lld %lld ", s[a], s[0]); 
	}
	puts("");
}

