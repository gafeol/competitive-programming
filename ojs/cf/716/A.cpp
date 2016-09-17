

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

int main (){
	scanf("%d%d", &n, &m);
	int res = 0;
	for(int a=0;a<n;a++){
		scanf("%d", &s[a]);
		if(a != 0){
			if(s[a] - s[a-1] > m)
				res = 0;
		}
		res++;
	}
	printf("%d\n", res);
}
