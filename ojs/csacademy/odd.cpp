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

int cnt(int i){
	int ans = 0;
	for(int a=1;a<=i;a++){
		if(i%a==0)
			ans = 1-ans;
	}
	return ans;
}

int main (){
	scanf("%d%d", &n, &m);
	int res = 0;
	for(int a=n;a<=m;a++){
		if(cnt(a)){
			res++;
		}
	}
	printf("%d\n", res);
}
