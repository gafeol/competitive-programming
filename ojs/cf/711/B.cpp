#include <bits/stdc++.h>
using namespace std;
#define fst first
#define snd second
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;
#define pb push_back
#define for_tests(t, tt) int t; scanf("%d", &t); for(int tt = 1; tt <= t; tt++)
template<typename T> inline T abs(T t) { return t < 0? -t : t; }
const ll modn = 1000000007;
inline ll mod(ll x) { return x % modn; }

const int MAXN = 510;

int n;
ll m[MAXN][MAXN];

ll sum;

bool testa(){
	ll soma = 0;
	for(int a=0;a<n;a++){
		soma = 0;
		for(int b=0;b<n;b++){
			soma += m[a][b];
		}
		if(soma != sum) return false;
	}
	for(int b=0;b<n;b++){
		soma = 0;
		for(int a=0;a<n;a++){
			soma += m[a][b];
		}
		if(soma != sum) return false;
	}
	soma = 0;
	for(int a=0;a<n;a++){
		soma += m[a][a]; 
	}
	if(soma != sum) return false;
	soma = 0;
	for(int a=0;a<n;a++){
		soma += m[a][n-a-1];
	}
	if(soma != sum) return false;

	return true;
}

int main (){
	scanf("%d", &n);
	if(n == 1){
		puts("1");
		return 0;
	}
	int i, j;
	for(int a=0;a<n;a++){
		for(int b=0;b<n;b++){
			scanf("%lld", &m[a][b]);
			if(m[a][b] == 0){
				i = a;
				j = b;
			}
		}
	}
	for(int a=0;a<n;a++){
		if(a == i) continue;
		sum = 0;
		for(int b=0;b<n;b++){
			sum += (ll)m[a][b];
		}
		break;
	}
	ll s = 0;
	for(int b=0;b<n;b++){
		s += (ll)m[i][b];
	}
	ll val = sum - s;
	m[i][j] = val;
	if(val > 0 && testa())
		printf("%lld\n", val);
	else
		puts("-1");
}
