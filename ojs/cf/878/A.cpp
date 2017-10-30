
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

const int MAXN = 45;

int n, m, k;
int s[MAXN];

int main (){
	scanf("%d", &n);
	memset(s, -1, sizeof(s));
	for(int a=0;a<n;a++){
		int x;
		char op;
		scanf(" %c %d", &op, &x);
		for(int i=0;i<10;i++){
			if(op == '&'){
				if(x&(1<<i)) continue;
				s[i] = 0;
			}
			else if(op == '|'){
				if(x&(1<<i))
					s[i] = 1;
			}
			else{
				if(x&(1<<i)){
					if(s[i] == -1)
						s[i] = 2;
					else if(s[i] == 2)
						s[i] = -1;
					else
						s[i] = 1 - s[i];
				}
			}
		}
	}
	int an, o, xo;
	an = 0;
	o = 0;
	xo = 0;
	for(int a=9;a>=0;a--){
		an *= 2;
		if(s[a] != 0)
			an += 1;
	}
	for(int a=9;a>=0;a--){
		o *= 2;
		if(s[a] == 1)
			o += 1;
	}
	for(int a=9;a>=0;a--){
		xo *= 2;
		if(s[a] == 2)
			xo += 1;
	}
	printf("3\n& %d\n| %d\n^ %d\n", an, o, xo);
}

