#include <bits/stdc++.h>
using namespace std;
#define fst first
#define snd second
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;
#define pb push_back
#define for_tests(t, tt) int t; scanf("%d", &t); for(int tt = 1; tt <= t; tt++)
template<typename T> inline T abs(T t) { return t < 0? -t : t; }
const ll modn = 1000000007;
inline ll mod(ll x) { return x % modn; }

const int MAXN = 212345;

int n, m, k, s[MAXN];
ll sum[MAXN];

int main (){
	scanf("%d", &n);
	for(int a=0;a<=n;a++){
		if(a > 0)
			sum[a] = sum[a-1];
		sum[a] += a;
	}
	int i = 1;
	ll res = 0;
	for(int a=1;a<=n;a++){
		scanf("%d", &s[a]);
		if(s[a] == 0){
			res += sum[a-i];
			i = a+1;
		}
	}
	res += sum[n+1 - i];
	printf("%lld\n", res);

}
