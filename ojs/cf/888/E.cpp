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

const int MAXN = 212345;

int n, k;
ll m;
ll s[MAXN];
ll sum;
inline ll mod(ll x) { return x % m; }

ll res;

map<ll, int> mrk;

int main (){
	res = 0;
	scanf("%d%lld", &n, &m);
	for(int a=0;a<n;a++)
		scanf("%lld", s+a);
	int mid = n/2;
	mrk[0] = 1;
	for(int bm=0;bm<(1<<mid);bm++){
		sum = 0;
		for(int i=0;i<19;i++){
			if((bm&(1<<i))){
				sum = mod(sum + s[i]);
			}
		}
		res = max(res, sum);
		mrk[sum] = 1;	
	}
	int beg = mid;
	mid = n - (n/2);
	for(int bm=0;bm<(1<<mid);bm++){
		sum = 0;
		for(int i=0;i<19;i++){
			if((bm&(1<<i))){
				sum = mod(sum + s[i+beg]);
			}
		}
		auto it = mrk.lower_bound(m - sum);
		res = max(res, sum);
		if(it == mrk.begin()) continue;
		res = max(res, sum + (--it)->fst);
	}
	printf("%lld\n", res);
}
