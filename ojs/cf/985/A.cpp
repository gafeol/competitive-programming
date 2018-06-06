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

set<int> p;

int main (){
	scanf("%d", &n);
	for(int a=0;a<n/2;a++){
		scanf("%d", s+a);
		s[a]--;
		p.insert(s[a]);
	}
	int ans = INT_MAX;
	for(int t=0;t<2;t++){
		int res = 0;
		for(int a=t;a<n;a+=2){
			res += abs(a - *p.begin());
			p.erase(p.begin());
		}
		ans = min(ans, res);
		for(int a=0;a<n/2;a++)
			p.insert(s[a]);
	}
	printf("%d\n", ans);
}

