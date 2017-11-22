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
vector<int> s;

int main (){
	scanf("%d%d", &n, &m);
	for(int a=0;a<m;a++){
		int x;
		scanf("%d", &x);
		s.pb(x);
	}
	sort(s.begin(), s.end());
	for(int a=0;a<n;a++){
		int l, r;
		scanf("%d%d", &l, &r);
		printf("%d\n", (int)(upper_bound(s.begin(), s.end(), r) - lower_bound(s.begin(), s.end(), l)));
	}
}

