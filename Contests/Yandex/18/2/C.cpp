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

int n, m, k, c, d, ca, da;
int s[MAXN],h[MAXN];

int main (){
	scanf("%d%d%d%d%d%d", &n, &m, &d, &c, &da, &ca);
	for(int a=0;a<n;a++)
		scanf("%d", h+a);
	sort(h, h+n);
	int res = 0;
	int mm = m;
	for(int q=0;q*ca <= mm;q++){
		int cnt = 0;
		m = mm;
		m -= q*ca;
		for(int a=0;a<n;a++){
			if(h[a] <= q*da){
				cnt++;
				continue;
			}
			if(((h[a] - q*da + d - 1)/d)*c > m) break;
			m -= ((h[a] - q*da + d - 1)/d)*c; 
			cnt++;
		}
		res = max(res, cnt);
	}
	printf("%d\n", res);
}

