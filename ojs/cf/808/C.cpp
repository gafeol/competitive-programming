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
int s[MAXN], res[MAXN];
int ind[MAXN];

bool cmp(int a, int b){
	return s[a] > s[b];
}

int main (){
	scanf("%d%d", &n, &k);
	int fill = 0;
	for(int a=0;a<n;a++){
		scanf("%d", s+a);
		fill += (s[a] + 1)/2;
		res[a] = (s[a] + 1)/2;
		ind[a] = a;
	}
	if(k < fill){
		puts("-1");
		return 0;
	}
	sort(ind, ind+n, cmp);
	int sob = k - fill;
	for(int a=0;a<n;a++){
		int i = ind[a];	
		int pour = min(sob, s[i] - res[i]);
		sob -= pour;
		res[i] += pour; 
	}
	for(int a=0;a<n;a++){
		printf("%d ", res[a]);
	}
}
