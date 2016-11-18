

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

vector<int> p;

char s[10];

int main (){
	for(int a=2;a<=100;a++){
		int pri = 1;
		for(int b=2;b<a;b++){
			if(a%b==0)
				pri = 0;
		}
		if(pri){
			p.pb(a);
		}
	}
	int cnt = 0;
	int i = 0;
	int mul = 1;
	debug("%d\n", (int)p.size());
	for(;i<18;i++){
		if(p[i]*mul > 100)
			break;
		printf("%d\n", p[i]*mul);
		fflush(stdout);

		scanf(" %s", s);
		fflush(stdout);
		if(s[0] == 'y'){
			mul = p[i];
			cnt++;
			i--;
		}
		if(cnt == 2) break;
	}
	if(cnt == 2) printf("composite\n");
	else
		puts("prime");
	fflush(stdout);
}
