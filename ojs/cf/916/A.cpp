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
#define debug(args...) fprintf(stderr,args)
#else
#define debug(args...)
#endif //ONLINE_JUDGE
template<typename T> inline T abs(T t) { return t < 0? -t : t; }
const ll modn = 1000000007;
inline ll mod(ll x) { return x % modn; }

const int MAXN = 212345;

int n, m, k;

bool l(int h, int m){
	if(h%10 == 7) return 1;
	h /= 10;
	if(h%10 == 7) return 1;
	h = m;
	if(h%10 == 7) return 1;
	h /= 10;
	if(h%10 == 7) return 1;
	return 0;
}



int main (){
	scanf("%d", &n);
	int h, m;
	scanf("%d %d", &h, &m);
	int res =0;
	while(!l(h, m)){
		res++;
		m -= n;
		if(m < 0){
			m += 60;
			h--;
		}
		if(h < 0)
			h = 23;
	}
	printf("%d", res);
}

