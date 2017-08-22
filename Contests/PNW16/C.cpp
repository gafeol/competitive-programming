
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

int s[MAXN];
int sum[MAXN];
set<int> s1;

int main (){
	int n, k, r;
	scanf("%d %d %d", &n, &k, &r);
	for (int i=0;i<k;i++) {
		scanf("%d", &s[i]);
		s1.insert(s[i]);
	}
	int resp = 0;
	for (int i=1;i<=n-r+1;i++) {
		int t = 0;
		set<int>::iterator it = s1.upper_bound(i-1);
		set<int>::iterator it2 = s1.upper_bound(i-1);
		if (it == s1.end()) {
			t = 0;
		}
		else {
			if (*it <= i+r-1) t++;
			it2++;
			if (it2 != s1.end() && *it2 <= i+r-1) {
				t++;
			}
		}
		if (t < 2) {
			for (int j=i+r-1;j>=i && t!=2;j--) {
				if (s1.find(j) == s1.end()) {
					resp++;
					s1.insert(j);
					t++;
				}
			}
		}
	}
	printf("%d\n", resp);
}

