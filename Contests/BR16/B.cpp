
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
int s[MAXN][4];
vector<int> conn[MAXN];

int main (){
	int a, b;
	scanf("%d %d %d %d", &n, &m, &a, &b);
	set<pair<int, int> > s2;
	for(int i=0;i<m;i++){
		int c, d;
		scanf("%d %d", &c, &d);
		c--; d--;
		conn[c].pb(d);
		conn[d].pb(c);
		s[c][0]++;
		s[d][0]++;
	}
	for (int i=0;i<n;i++) {
		s2.insert({s[i][0], i});
	}
	while(s2.size()) {
		pair<int, int> c = *s2.begin();
		pair<int, int> d = *s2.rbegin();
		if (c.first < a) {
			s2.erase(c);
			for (int i=0;i<conn[c.second].size();i++) {
				k = conn[c.second][i];
				if (s2.find({s[k][0], k}) != s2.end()) {
					s2.erase({s[k][0], k});
					s2.insert({--s[k][0], k});
				}
			}
		}
		else if (s2.size()-1-d.first < b) {
			s2.erase(d);
			for (int i=0;i<conn[d.second].size();i++) {
				k = conn[d.second][i];
				if (s2.find({s[k][0], k}) != s2.end()) {
					s2.erase({s[k][0], k});
					s2.insert({--s[k][0], k});
				}
			}
		}
		else break;
	}
	printf("%d\n", (int)s2.size());
}

