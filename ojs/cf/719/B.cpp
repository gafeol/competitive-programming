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

const int MAXN = 212345;

int n, m, k;
int s[MAXN];

int res;

void solve(){
	int q[2], w[2];
	q[0] = q[1] = w[1] = w[0] = 0;
	int eh = 0;
	for(int a=0;a<n;a++){
		eh = a&1;
		if(eh != s[a]){
			w[s[a]]++;
		}
	}
	res = min(res, max(w[0], w[1]));
}

int ini[MAXN];

int main (){
	scanf("%d", &n);
	res = INT_MAX;
	for(int a=0;a<n;a++){
		char c;
		scanf(" %c", &c);
		if(c == 'r')
			s[a] = 1;
		else
			s[a] = 0;
		ini[a] = s[a];
	}
	solve();
	for(int a=0;a<n;a++){
		s[a] = 1-s[a];
	}
	solve();
	printf("%d\n", res);
}
