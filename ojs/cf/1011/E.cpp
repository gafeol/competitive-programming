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

vector<int> val;


int cvt(int x, int k){
	return x%k;
}
int dp[MAXN];

int gcd(int a, int b){
	if(b == 0) return a;
	return gcd(b, a%b);
}

int main (){
	scanf("%d%d", &n, &k);
	for(int a=0;a<n;a++){
		scanf("%d", s+a);
		val.pb(cvt(s[a], k));
	}
	sort(val.begin(), val.end());

	val.erase(unique(val.begin(), val.end()), val.end());
	int gc = 0;
	for(int x: val){
		gc = gcd(x, gc); 	
	}
	int ans = gcd(gc, k);
	printf("%d\n", k/ans);
	for(int a=0;a<k;a++){
		if(a%ans == 0){
			printf("%d ", a);
		}
	}
	puts("");
}

