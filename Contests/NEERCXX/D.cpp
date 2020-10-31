
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
int bit[MAXN];

void upd(int i, int val){
	i+=2;

	while(i < MAXN){
		bit[i] += val;
		i += (i&-i);
	}
}

int qry(int i){
	i += 2;
	int ans = 0;
	while(i > 0){
		ans += bit[i];
		i -= (i&-i);
	}
	return ans;
}

int main (){
	int t;
	scanf("%d %d", &n, &t);
	t--;
	map<int, int> m2;
	set<pair<int, int> > s2;
	set<int> s3;
	for(int i=0;i<n;i++){
		scanf("%d", &s[i]);
		s3.insert(max(0, s[i]-(i+1)));
		s[i] = max(s[i], i+1);
	}
	int j = 1;
	for (auto a : s3) {
		m2[a] = j;
		s2.insert({a, j});
		j++;
	}
	int mx = 0;
	s2.insert({-1, 0});
	for (int i=0;i<n;i++) {
		int p = t - s[i];
		set<pair<int, int> >::iterator it = s2.upper_bound({p, j+1});
		if (it == s2.begin()) continue;
		it--;
		p = it->second;
		//printf("%d %d\n", p, m2[max(0, s[i]-(i+1))]);
		if (p >= 0) {
			//printf("q = %d %d\n", qry(p), p);
			mx = max(mx, qry(p)+1);
		}
		upd(m2[max(0, s[i]-(i+1))], 1);
	}
	printf("%d\n", mx);
}








