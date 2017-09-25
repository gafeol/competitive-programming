
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
int pos[MAXN];

int main (){
	scanf("%d %d", &n, &m);
	multiset<int> s2;
	long long mx = 0;
	for(int a=0;a<n;a++){
		scanf("%d", &s[a]);
		if ((a+1)%(m+1) == 0 && a!=0) {
			pos[a] = 1;
		}
		mx += s[a];
	}
	for (int i=n-1;i>=0;i--) {
		s2.insert(s[i]);
		if (pos[i] == 1) {
			long long t = *s2.rbegin();
			s2.erase(s2.find(t));
			mx -= t;
		}
	}
	printf("%lld\n", mx);
}

