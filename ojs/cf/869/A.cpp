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
int v[MAXN];

int mrk[2123456];

int main (){
	scanf("%d", &n);
	for(int a=0;a<n;a++){
		scanf("%d", s+a);
		mrk[s[a]] = 1;
	}
	for(int a=0;a<n;a++){
		scanf("%d", v+a);
		mrk[v[a]] = 1;
	}
	int res = 0;
	for(int a=0;a<n;a++){
		for(int b=0;b<n;b++){
			if(mrk[(s[a]^v[b])])
				res++;
		}
	}
	if(res&1)
		puts("Koyomi");
	else
		puts("Karen");
}

