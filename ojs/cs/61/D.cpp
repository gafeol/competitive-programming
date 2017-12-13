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

int pil[MAXN], top;

int bb(int i, int j, int val){
	while(i < j){
		int m = (i + j+1)/2;
		if(pil[m] <= val)
			i = m;
		else
			j = m-1;
	}
	return i;
}

int lis(){
	pil[top++] = INT_MIN;
	for(int a=0;a<n;a++){
		int i = 1+bb(0,top-1, s[a]); 
		if(i == top) top++;
		pil[i] = s[a];
		/*printf("lis:\n");
		for(int i=1;i<top;i++){
			printf("%d\n", pil[i]);
		}*/
	
	}
	debug("top %d\n", top);
	return top-1;
}

int main (){
	scanf("%d", &n);
	for(int a=0;a<n;a++){
		scanf("%d", s+a);
		s[a] -= a;
		debug("%d ", s[a]);
	}
	debug("\n");
	printf("%d\n", n - lis());
}

