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

int bit[MAXN];

pii s[MAXN];

int res[MAXN], mrk[MAXN];

int main (){
	scanf("%d%d", &n, &m);
	for(int a=0;a<m;a++){
		int i, j;
		scanf("%d %d", &i, &j);
		s[a] = pii(i, j);
		mrk[i]++;
		mrk[j+1]--;
	}
	int ans = 0;
	for(int a=1;a<=n;a++){
		mrk[a] += mrk[a-1];
		 if(mrk[a] == 1)
			res[a] = 1;
		if(mrk[a] == 0)
			ans++;
	}
	for(int a=1;a<=n;a++){
		res[a] += res[a-1];
	}
	for(int a=0;a<m;a++){
		printf("%d\n", ans + res[s[a].snd] - res[s[a].fst-1]);
	}
}

