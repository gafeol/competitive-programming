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

int n, m, k, A, B;
int s[MAXN], ind[MAXN];

map<int, int> mrk;


bool has(int x){
	return (mrk.find(x) != mrk.end());
}

void go(int u, int g){
	debug("go(%d %d)\n", u, g);
	if(!has(s[u]) || (ind[u] != g && ind[u] != 0)){
		puts("NO");
		exit(0);
	}
	if(ind[u] == g) return;
	ind[u] = g;
	int G = (g == 1 ? A:B);
	go(mrk[G - s[u]], g);
}

int main (){
	scanf("%d %d %d", &n, &A, &B);
	for(int a=1;a<=n;a++){
		scanf("%d", &s[a]);
		mrk[s[a]] = a;
	}
	for(int a=1;a<=n;a++){

		if(ind[a] != 0) continue;
		if(has(A - s[a]) && !has(B - s[a]))
			go(a, 1);
		else if(!has(A - s[a]) && has(B - s[a]))
			go(a, 2);
	}
	for(int a=1;a<=n;a++){
		if(ind[a] == 0){
			puts("NO");
			return 0;
		}
	}
	puts("YES");
	for(int a=1;a<=n;a++){
		printf("%d ", ind[a]-1);
	}
	printf("\n");

}
