#include <bits/stdc++.h>
using namespace std;
#define fst first
#define snd second
#define int ll
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
pii s[MAXN];
int res[MAXN];

map<int, vector<int> > mrk[2];
map<int, int> foi[2];

void go(int *i, int *j, int d){
	int vi = *i, vj = *j;
	int ii, jj, iii, jjj;
	if(!d){
		if(*i == 0 || *j == 0){
			ii = n;
			jj = vj - vi + n;

			jjj = m;
			iii = vi + m - vj;

			if(jj >= 0 && jj <= m){
				*i = ii;
				*j = jj;
			}
			else{
				*i = iii;
				*j = jjj;
			}
		}
		else{
			ii = 0;
			jj = vj - vi;

			jjj = 0;
			iii = vi - vj;

			if(jj >= 0 && jj <= m){
				*i = ii;
				*j = jj;
			}
			else{
				*i = iii;
				*j = jjj;
			}
		}
	}
	else{
		if(*i == n || *j == 0){
			ii = 0;
			jj = vj + vi;

			jjj = m;
			iii = vi - m + vj;

			if(jj >= 0 && jj <= m){
				*i = ii;
				*j = jj;
			}
			else{
				*i = iii;
				*j = jjj;
			}
		}
		else{
			ii = n;
			jj = vj + vi - n;

			jjj = 0;
			iii = vi + vj;

			if(jj >= 0 && jj <= m){
				*i = ii;
				*j = jj;
			}
			else{
				*i = iii;
				*j = jjj;
			}
		}
	}
}

bool corner(int i, int j){
	return ((i == 0 && j == 0) || (i == 0 && j == m) || (i == n && j == 0) || (i == n && j == m));
}

main (){
	scanf("%lld%lld%lld", &n, &m, &k);
	for(int a=0;a<k;a++){
		int i, j;
		scanf("%lld %lld", &i, &j);
		mrk[0][i-j].pb(a);
		mrk[1][i+j].pb(a);
		s[a] = pii(i, j);
	}
	int i = 0, j = 0, dir = 0, t = 0;
	while(1){
		debug("%lld %lld %lld %lld\n", i, j, dir, t);
		int diag = i - j;
		if(dir == 1)
			diag = i + j;
		if(foi[dir][diag] == 1) break;
		foi[dir][diag] = 1;
		for(int u: mrk[dir][diag]){
			if(res[u] == 0)
				res[u] = t + abs(s[u].fst - i);
		}

		int ii = i;
		go(&i, &j, dir);
		dir ^= 1;
		t += abs(ii - i);
		if(corner(i, j)) break;
	}
	for(int a=0;a<k;a++){
		if(res[a] == 0) res[a] = -1;
		printf("%lld\n", res[a]);
	}
}
