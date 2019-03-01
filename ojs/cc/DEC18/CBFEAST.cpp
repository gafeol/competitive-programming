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

const ll MAXK = 1000000000;

struct arv{
	int mx[2];
	int tot;

	arv* l, r;

	arv(){
		mx[0] = mx[1] = tot = 0;
		l = r = NULL;
	}

	L(){
		if(l == NULL)
			l = new arv();
		return l;
	}
	R(){
		if(r == NULL)
			r = new arv();
		return r;
	}
}; 

int n, m, k;
int s[MAXN];

int main (){
	scanf("%d%d", &n, &k);
	for(int a=0;a<n;a++){
		int t;
		scanf("%d", &t);	
		if(t == 3){
			scanf("%d", &x);
			printf("%d\n", qry(x));
		}
	}
}

