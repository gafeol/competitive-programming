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

const int MAXN = 212;

int n, m, k;
int s[2][MAXN];

int main (){
	scanf("%d%d", &n, &m);
	int nn, nm;
	scanf("%d",&nn);
	int val;
	for(int a=0;a<nn;a++){
		scanf("%d", &val);
		s[0][val] = 1;
	}
	scanf("%d",&nm);
	for(int a=0;a<nm;a++){
		scanf("%d", &val);
		s[1][val] = 1;
	}
	for(int a=0;a<n*m*2;a++){
		if(s[0][a%n] || s[1][a%m]){
			s[0][a%n] = s[1][a%m] = 1;
		}
	}
	for(int a=0;a<n;a++){
		if(s[0][a] == 0){
			puts("No");
			return 0;
		}
	}
	for(int a=0;a<m;a++){
		if(s[1][a] == 0){
			puts("No");
			return 0;
		}
	}
	puts("Yes");
}
