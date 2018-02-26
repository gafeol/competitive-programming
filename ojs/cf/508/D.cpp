#include <bits/stdc++.h>
using namespace std;
#define fst first
#define snd second
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<char, char> pcc;
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
char s[MAXN][4];

map<pcc, vector<int> > pre, pos;

int l[MAXN], r[MAXN], head=-1;

int main (){
	scanf("%d", &n);
	memset(l, -1, sizeof(l));
	memset(r, -1, sizeof(r));
	for(int a=0;a<n;a++){
		scanf(" %s", s+a);
		pre[pcc(s[0], s[1])].pb(a);
		pos[pcc(s[1], s[2])].pb(a);
	}
	vector<int> odd;
	for(int a=0;a<n;a++){
		if(
	}
}

