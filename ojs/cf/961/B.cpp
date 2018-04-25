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
int t[MAXN];

int main (){
	scanf("%d%d", &n, &k);
	for(int a=0;a<n;a++){
		scanf("%d", s+a);
	}
	for(int a=0;a<n;a++)
		scanf("%d", t+a);
	int b = n-1;
	ll sum = 0;
	ll sk = 0;
	while(b >= k){
		sum += s[b]*t[b];
		b--;
	}
	for(int a=0;a<k;a++)
		sk += s[a];
	ll res = 0;
	for(int a=0;a+k-1<n;a++){
		res = max(res, sk + sum);		
		sk -= s[a];
		sk += s[a+k];
		if(t[a])
			sum += s[a];
		if(t[a+k])
			sum -= s[a+k];
	}
	printf("%lld\n", res);
}

