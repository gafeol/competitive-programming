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
ll sum[MAXN];


int main (){
	scanf("%d", &n);
	for(int a=0;a<n;a++){
		scanf("%lld", s+a);
	}
	for(int a=0;a<n-1;a++){
		sum[a] = abs(s[a] - s[a+1]); 
		if(a&1) sum[a] *= -1;
	}
	n--;
	int i = 0, j = 0;
	ll ans = 0, som = 0;
	while(j < n){
		som += sum[j];
		while(som < 0){
			som -= sum[i];
			i++;
		}
		ans = max(ans, som);
		j++;
	}
	for(int a=0;a<n;a++){
		sum[a] *= -1;
	}
	i = 0;
	j = 0;
	som = 0;
	while(j < n){
		som += sum[j];
		while(som < 0){
			som -= sum[i];
			i++;
		}
		ans = max(ans, som);
		j++;
	}
	printf("%lld\n", ans);
}
