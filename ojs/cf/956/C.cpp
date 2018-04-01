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

int mx[MAXN];

int main (){
	scanf("%d", &n);
	for(int a=0;a<n;a++){
		scanf("%d", s+a);
		mx[a] = s[a]+1;
		if(a > 0)
			mx[a] = max(mx[a], mx[a-1]);
	}
	for(int a=n-1;a>=0;a--)
		mx[a] = max(mx[a], mx[a+1]-1);
	int cnt = 0;
	ll res = 0;
	for(int a=0;a<n;a++){
		if(mx[a] > cnt)
			cnt++;
		res += cnt - s[a] - 1;
	}
	printf("%lld\n", res);
}

