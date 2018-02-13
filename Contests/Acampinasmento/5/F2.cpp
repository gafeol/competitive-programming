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
#define debug(args...) //fprintf(stderr,args)
#else
#define debug(args...)
#endif //ONLINE_JUDGE
template<typename T> inline T abs(T t) { return t < 0? -t : t; }
const ll modn = 1000000007;
inline ll mod(ll x) { return x % modn; }

const int MAXN = 212345;

ll n;
ll qtd[MAXN];

vector<ll> fib;
vector<int> s;

void re(ll p){
	p--;
	int lz = 1;
	for(int i = fib.size()-1;i>=0;i--){
		debug("p %lld i %d\n", p, i);
		if(i > 0) debug("fib[%d-1] %lld\n", i, fib[i-1]);
		if(i == 0){
			if(p == 0 && lz) continue;
			s.pb(p);
		}
		else{
			if(p >= fib[i-1]){
				p -= fib[i-1];
				debug("ps 10\n");
				s.pb(1);
				s.pb(0);
				lz = 0;
				i--;
			}
			else{
				if(lz) continue;
				s.pb(0);
				debug("ps 0");
			}
		}
	}
}

ll q[MAXN][4], dp[MAXN][4];

ll go(int i, int lo){
	if(i >= s.size()){
		q[i][lo] = 1;
		dp[i][lo] = 0;
		return 1;
	}
	if(q[i][lo] != -1) return q[i][lo];
	q[i][lo] = 0;
	dp[i][lo] = 0;
	if(lo || s[i] == 1){
		q[i][lo] += go(i+2, lo);
		dp[i][lo] += q[i+2][lo] + dp[i+2][lo];
	}
	int llo = max(lo, (int)(s[i] == 1));
	q[i][lo] += go(i+1, llo);
	dp[i][lo] += dp[i+1][llo];
	debug("i %d lo %d q %lld dp %lld\n", i, lo, q[i][lo], dp[i][lo]);
	return q[i][lo];
}

vector<int> aux;

int main (){
	freopen("fibonacci.in", "r", stdin);
	freopen("fibonacci.out", "w", stdout);
	memset(q, -1, sizeof(q));
	scanf("%lld", &n);
	if(n == 0){
		printf("0\n");
		return 0;
	}
	qtd[1] = 1;
	qtd[2] = 1;
	ll tam = 1;
	while(n > tam*qtd[tam]){
		n -= tam*qtd[tam];
		tam++;
		if(tam > 2)
			qtd[tam] = qtd[tam-1] + qtd[tam-2];
	}
	debug("tam %lld\n", tam);
	ll i = n/tam + (n%tam != 0);	
	debug("i %lld\n", i);
	fib.pb(2);
	fib.pb(3);
	while(fib[fib.size()-2] <= i){
		int sz = fib.size()-1;
		fib.pb(fib[sz] + fib[sz-1]);
		debug("fib[%d] = %lld\n", sz+1, fib[sz+1]);
	}
	re(i);	
	aux.pb(1);
	while(aux.size() + s.size() < tam)
		aux.pb(0);
	for(int a=0;a<s.size();a++)
		aux.pb(s[a]);
	s.clear();
	debug("NUMERO\n");
	for(int a=0;a<aux.size();a++){
		s.pb(aux[a]);
		debug("%d", s[a]);
	}
	debug("\n");

	ll res = 0;
	if((n%tam) != 0){
		for(int a=0;a<tam - n%tam;a++){
			res -= s[s.size()-1-a];
			debug("limpa %d\n", s[s.size()-1-a]);
		}
	}
	go(0, 0); 
	debug("%lld\n", dp[0][0]);
	res += dp[0][0];
	printf("%lld\n", res);
}
