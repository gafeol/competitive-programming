#include<bits/stdc++.h>
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

int s[MAXN], ans;

int main (){
	scanf("%d", &n);
	ans = 0;
	int pri = 0;
	int cg, cp;
	cg = cp = 0;
	for(int a=0;a<n;a++){
		scanf("%d", &s[a]);
		ans ^= !(s[a]&1);
		if(ans)
			puts("1");
		else
			puts("2");
	}

}
