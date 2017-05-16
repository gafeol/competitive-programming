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
#define cos asdasda

const int MAXN = 212345;

int n, m, k;
int f[MAXN], b[MAXN];
int s[MAXN];

multiset<pii> cos[4];

int main (){
	scanf("%d", &n);
	for(int a=0;a<n;a++){
		scanf("%d", &s[a]);
	}
	for(int a=0;a<n;a++){
		scanf("%d", &f[a]);
		cos[f[a]].insert(pii(s[a], a));
	}
	for(int a=0;a<n;a++){
		scanf("%d", &b[a]);
		cos[b[a]].insert(pii(s[a], a));
	}
	scanf("%d", &m);	
	for(int a=0;a<m;a++){
		int val;
		scanf("%d", &val);
		if(cos[val].empty())
			puts("-1");
		else{
			pii aux = (*cos[val].begin());
			printf("%d ", aux.fst);
			cos[val].erase(cos[val].begin());
			int i = aux.snd;
			if(val == f[i])
				cos[b[i]].erase(cos[b[i]].find(pii(s[i], aux.snd)));
			else
				cos[f[i]].erase(cos[f[i]].find(pii(s[i], aux.snd)));
		}
	}
}
