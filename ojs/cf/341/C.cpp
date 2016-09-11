
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

const int MAXN = 100010;

int n, p;

struct shark{
	ll l, r;
} s[MAXN];

int main (){
	scanf("%d%d", &n, &p);
	for(int a=0;a<n;a++)
		cin >> s[a].l >> s[a].r;
	double res = 0;
	for(int a=0;a<n;a++){
		ll din = 0;
		int nxt = (a+1)%n;
		tot = (s[nxt].r - s[nxt].l + 1)*(s[a].r - s[a].l + 1);
		ll i = s[a].l/p + (s[a].l%p != 0);
		ll f = s[a].r/p;
		ll ai  = f-i+1;
		ll inx = s[nxt].l/p + (s[nxt].l%p != 0);
		ll fnx = s[nxt].r/p;
		ll anx = fnx - inx + 1;
		res += 1-((s[a].r - s[a].l+1 - ai)/(s[a].r-s[a].l+1))*((s[nxt].r - s[nxt].l + 1 - anx)/(s[nxt].r - s[nxt].l + 1)); 
	}
	printf("%.15f\n", (double)res*1000);
}
