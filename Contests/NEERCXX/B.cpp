
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
vector<int> v[MAXN];

int main (){
	scanf("%d", &n);
	set<pair<int, int> > s;
	for (int i=0;i<n;i++) {
		s.insert({0, -i});
	}
	for(int i=0;i<n;i++){
		int a;
		scanf("%d", &a);
		set<pair<int, int> >::iterator it = s.upper_bound({a, 0});
		it--;
		pair<int, int> p = *it;
		s.erase(it);
		v[-p.second].push_back(a);
		s.insert({a, p.second});
	}
	for (int i=0;v[i].size();i++) {
		for (auto a : v[i]) {
			printf("%d ", a);
		}
		printf("\n");
	}
}

