#include <bits/stdc++.h>
using namespace std;
#define fst first
#define snd second
typedef unsigned long long ull;
typedef long long ll;
typedef pair<ll, int> pii;
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

const int MAXN = 100000000;

int n, m, k;
char s[MAXN];

map<pii, ll> mrk;

void go(ll x){
	ll xx = x;
	ll p = x%10;
	ll dez = 10;
	int cnt = 1;
	while(mrk.find(pii(p, cnt)) != mrk.end()){
		x/=10;
		p += dez*(x%10);
		dez *= 10;
		cnt++;
	}
	mrk[pii(p, cnt)] = xx;
}

int main (){
	scanf("%d", &n);
	clock_t c = clock();
	for(ll a=1989;((double)(clock() - c))/CLOCKS_PER_SEC < 0.9;a++){
		go(a);
	}
	for(int a=0;a<n;a++){
		scanf(" %s", s);
		int tam = strlen(s);
		int ini = tam;
		ll x = 0;
		for(int a=0;a<tam;a++){
			if(s[a] >= '0' && s[a] <= '9'){
				ini = min(ini, a);
				x *= 10;
				x += s[a] - '0';
			}
		}
		if(mrk.find(pii(x, tam - ini)) != mrk.end()){
			printf("%lld\n", mrk[pii(x, tam-ini)]);
		}
		else{
			if(s[ini] == '0')
				printf("1");

			for(int b=ini;b<tam;b++){
				printf("%c", s[b]);
			}
			putchar('\n');
		}
	}
}
