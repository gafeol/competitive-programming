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

ll i, j, ii, jj, k;

ll in(ll a, ll b){
	return (k >= a && k <= b);
}

int main (){
	scanf("%lld %lld %lld %lld %lld", &i, &j, &ii, &jj, &k);
	if(i > ii){
		swap(i, ii);
		swap(j, jj);
	}
	if(j >= ii){
		if(j >= jj){
			printf("%lld\n", jj - ii - in(ii, jj) + 1);
		}
		else
			printf("%lld\n", j - ii - in(ii, j) + 1);
	}
	else{
		puts("0");
	}
}
