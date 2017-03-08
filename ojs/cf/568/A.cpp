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

const int MAXN = 2123456;

ll n, m, k;
int s[MAXN], p[MAXN], mrk[MAXN];
int dez[MAXN];

int pal(int x){
	int xx = x;
	int cnt = 0;
	while(xx > 0){
		xx /= 10;
		cnt++;
	}
	for(int a=0;a<cnt/2;a++){
		if((x/dez[a])%10 == (x/dez[cnt-a-1])%10)
			continue;
		return 0;
	}
	return 1;
}

int main (){
	dez[0] = 1;
	for(int a=1;a<7;a++){
		dez[a] = dez[a-1]*10;
	}
	scanf("%lld%lld", &n, &m);
	p[0] = 0;
	s[1] = 1;
	for(ll a=2;a<=MAXN;a++){
		p[a] = p[a-1];
		s[a] = s[a-1] + pal(a);
		if(mrk[a]) continue;
		p[a]++;
		for(ll b = a; b*a < MAXN; b++){
			mrk[a*b] = 1;
		}
	}
	int i = 1;
	int res = 0;
	while(i < MAXN){
		if(n*s[i] >= m*p[i]){
			res = i;
		}
		i++;
	}
	printf("%d\n", res);
}
