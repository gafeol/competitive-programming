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
int s[MAXN], ind[MAXN];
int res[MAXN];

bool cmp(int a, int b){
	return s[a] > s[b];
}

int main (){
	scanf("%d", &n);
	for(int a=0;a<n;a++){
		ind[a] = a;
		scanf("%d", s+a);
	}
	sort(ind, ind+n, cmp);

	int c = 0;
	int qtd = -1, sz = 0;
	for(int i=0;i<n;i++){
		if(sz == 0){
			c++;			
			sz = n - s[ind[i]];
			qtd = s[ind[i]];

		}
		if(qtd != s[ind[i]]){
			puts("Impossible");
			return 0;
		}
		sz--;
		res[ind[i]] = c;
	}
	if(sz != 0){
		puts("Impossible");
		return 0;
	}
	puts("Possible");
	for(int a=0;a<n;a++){
		printf("%d ", res[a]);
	}
	puts("");
}


