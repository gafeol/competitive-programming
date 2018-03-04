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

const int MAXN = 11234;

int n, m, k;
char s[MAXN];

vector<int> pos[30];

int mrk[30];

int main (){
	scanf(" %s", s);
	n = strlen(s);
	for(int a=0;a<n;a++)
		pos[s[a]-'a'].pb(a);
	for(int a=n;a<2*n;a++)
		s[a] = s[a-n];
	int res = 0;
	for(int c=0;c<30;c++){
		int best = 0;
		if(pos[c].empty()) continue;
		for(int a=1;a<n;a++){
			for(int p: pos[c]){
				mrk[s[p+a]-'a']++;
			}
			int aux = 0;
			for(int a=0;a<30;a++){
				if(mrk[a] == 1)
					aux++;
				mrk[a] = 0;
			}
			best = max(best, aux);
		}
		res += best;
	}
	double ans = res;
	ans = ans/((double)n);
	printf("%.10f\n", ans);
}

