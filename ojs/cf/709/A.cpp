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

int n, b, d;

int main (){
	scanf("%d%d%d", &n, &b, &d);
	int sum = 0, ans = 0;
	for(int a=0;a<n;a++){
		int t;
		scanf("%d", &t);
		if(t <= b)
			sum += t;
		if(sum > d){
			ans++;
			sum = 0;
		}
	}
	printf("%d\n", ans);
}
