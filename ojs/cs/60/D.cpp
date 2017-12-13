#include <bits/stdc++.h>
using namespace std;
#define fst first
#define snd second
typedef unsigned long long ull;
typedef long long ll;
#define int ll 
typedef pair<int, int> pii;
#define pb push_back
#define for_tests(t, tt) int t; scanf("%lld", &t); for(int tt = 1; tt <= t; tt++)
#ifndef ONLINE_JUDGE
#define debug(args...) fprintf(stderr,args)
#else
#define debug(args...)
#endif //ONLINE_JUDGE
template<typename T> inline T abs(T t) { return t < 0? -t : t; }
const ll modn = 1000000007;
inline ll mod(ll x) { return x % modn; }

const int MAXN = 45;

int n, m, k;
ll s[MAXN][2];

unordered_map<ll, vector<int> > mrk;
unordered_map<ll, ll> un;

inline int ceil(int i, int j){
	return (i/j + (i%j != 0));
}

main (){
	scanf("%lld", &n);
	for(int a=0;a<n;a++)
		scanf("%lld %lld", &s[a][0], &s[a][1]);
	int m1 = n/2;
	int m2 = ceil(n, 2);
	for(int bm=0;bm<(1<<(m1));bm++){
		ll d = 0, q = 0;
		for(int a=0;a<m1;a++){
			if((1<<a)&bm){
				d += s[a][0];
				q++;
			}
			else{
				q--;
				d -= s[a][1];
			}
		}
		mrk[d].pb(q);
	}
	int res = LLONG_MAX, r[4];
	for(int bm=0;bm<(1<<m2);bm++){
		ll d = 0, q = 0;
		for(int a=0;a<m2;a++){
			if((1<<a)&bm){
				d += s[a+(m1)][0];
				q++;
			}
			else{
				q--;
				d -= s[a+(m1)][1];
			}
		}
		if(mrk.find(-d) != mrk.end()){
			vector<int> &v = mrk[-d]; 
			if(un.find(-d) == un.end()){
				sort(v.begin(), v.end());
				v.erase(unique(v.begin(), v.end()), v.end());
				un[-d] = 1;
			}
			for(const int it : v){
				if(res > abs(q + it)){
					res = abs(q + it);				
					r[0] = -d;
					r[1] = it;
					r[2] = bm;
				}
			}
		}
	}
	if(res == LLONG_MAX){
		puts("-1");
		return 0;
	}
	debug("%lld\n", res);
	for(int i=0;i < 4;i++)
		debug("%lld ", r[i]);
	debug("\n");
	for(int bm=0;bm<(1<<(m1));bm++){
		ll d = 0, q = 0;
		for(int a=0;a<m1;a++){
			if((1<<a)&bm){
				d += s[a][0];
				q++;
			}
			else{
				q--;
				d -= s[a][1];
			}
		}
		if(d == r[0] && q == r[1]){
			for(int a=0;a<m1;a++){
				if((1<<a)&bm)
					printf("0");
				else
					printf("1");
			}
			break;
		}
	}
	int bm = r[2];
	for(int a=0;a<m2;a++){
		if((1<<a)&bm)
			printf("0");
		else
			printf("1");
	}
}

