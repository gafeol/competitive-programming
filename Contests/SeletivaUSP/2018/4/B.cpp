#include <cstdio>
#include <algorithm>
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

int cnt =0, dif;

ll fat[MAXN];
ll dv;

int main (){
	fat[0] = 1;
	for(ll a=1;a<21;a++){
		fat[a] = fat[a-1]*a;
	}
	while(scanf("%d", &n) != EOF){
		dif = 0;
		cnt = 0;
		dv = 1;
		int nn = n;
		for(int a=2;a <= n && a*a<=nn;a++){
			if(n%a == 0) dif++;
			int sm = 0;
			while(n > 1 && n%a == 0){
				n /= a;
				cnt++;
				sm++;
			}
			dv *= fat[sm];
		}
		if(n > 1){
			dif++;
			cnt++;
		}
		printf("%d %lld\n", cnt, fat[cnt]/dv);
	}
}

