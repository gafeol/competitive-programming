
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
#define debug(args...)// fprintf(stderr,args)
#else
#define debug(args...)
#endif //ONLINE_JUDGE
template<typename T> inline T abs(T t) { return t < 0? -t : t; }
const ll modn = 1000000007;
inline ll mod(ll x) { return x % modn; }

const int MAXN = 212345;

int n, m, k;
char s[MAXN];

int go(int t){
	int r, l, pc = n-1, lst = n-1;
	debug("t = %d\n", t);
	while(1){
		while(pc >= 0 && s[pc] != 'P') pc--;
		while(lst >= 0 && s[lst] != '*') lst--;
		debug("lst %d pc %d\n", lst, pc);
		if(lst < 0) return 1;
		if(pc < 0) return 0;
		if(abs(lst - pc) > t){
			pc--;
			debug("continuar\n");
			continue;
		}
		r = lst;
		l = lst;
		int cr = 0, cl = 0;
		if(lst < pc){
			cr += abs(pc - lst);
			cl += abs(pc - lst);
		}
		debug("l %d r %d\n", l, r);
		while(r > 0){
			int cus = 1;
			if(r > pc)
				cus++;
			if(cus + cr <= t){
				cr += cus;
				r--;
			}
			else
				break;
		}
		while(l > 0){
			int cus = 1;
			if(l <= pc)
				cus++;
			if(cus + cl <= t){
				cl += cus;
				l--;
			}
			else
				break;
		}
		debug("l %d r %d\n", l, r);
		pc--;
		lst = min(lst, min(r, l)) - 1;
	}
}

int main (){
	scanf("%d", &n);
	for(int a=0;a<n;a++){
		scanf(" %c", &s[a]);
	}
	int i = 0, j = 2*n;
	while(i < j){
		int m = ( i + j)/2;
		if(go(m))
			j = m;
		else
			i = m + 1;
	}
	printf("%d\n", i);
}

