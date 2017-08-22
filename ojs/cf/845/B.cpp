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

int main (){
	for(int a=0;a<6;a++){
		char c;
		scanf("%c", &c);	
		s[a] = c-'0';
	}
	int mn = 6;
	for(int a=0;a<=999999;a++){
		int aa = a;
		int cst = 0;
		for(int i=0;i<6;i++){
			v[i] = aa%10;
			cst += (v[i] != s[i]);
			aa /= 10;
		}
		if(v[0]+v[1]+v[2] == v[3] + v[4] + v[5]){
			mn = min(cst, mn);
		}
	}
	printf("%d\n", mn);
}

