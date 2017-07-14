#include <bits/stdc++.h>
using namespace std;
#define fst first
#define snd second
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<int, pii> pip;
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

int n, m, k, deg;
pip res[4123];
int cnt[10];

inline bool check(int a, int b, int p){
	if(a%10 == b%10 && a%10 == 0)
		return false;

	for(int i=0;i<10;i++)
		cnt[i] = 0;

	while(a != 0){
		cnt[a%10]++;
		a /= 10;
	}
	while(b != 0){
		cnt[b%10]++;
		b /= 10;
	}
	while(p != 0){
		cnt[p%10]--;
		p /= 10;
	}
	for(int i=0;i<10;i++)
		if(cnt[i] != 0)
			return false;
	return true;
}

int main (){
	for(int a = 10;a <= 99;a++){
		for(int b = a;b <= 99;b++){
			int m = a*b;
			if(m > 9999) break;
			if(m <= 999) continue;
			if(check(a, b, m))
				res[deg++] = pip(m, pii(a, b));
		}
	}
	for(int a = 100;a <= 999;a++){
		for(int b = a;b <= 999;b++){
			int m = a*b;
			if(m > 999999) break;
			if(m <= 99999) continue;
			if(check(a, b, m))
				res[deg++] = pip(m, pii(a, b));
		}
	}

	for(int a = 1000;a <= 9999;a++){
		for(int b = a;b <= 9999;b++){
			int m = a*b;
			if(m > 99999999) break;
			if(m <= 9999999) continue;
			if(check(a, b, m))
				res[deg++] = pip(m, pii(a, b));
		}
	}
	sort(res, res+deg);
	for_tests(t, tt){
		int l, r;
		scanf("%d%d", &l, &r);
		int i = lower_bound(res, res+deg, pip(l, pii(0, 0))) - res;
		int j = upper_bound(res, res+deg, pip(r, pii(0, 0))) - res;
		printf("Case %d:\n", tt);
		for(int a=i;a<j;a++)
			printf("%d=%dx%d\n", res[a].fst, res[a].snd.fst, res[a].snd.snd);
		if(i > j)
			printf("NONE\n");
	}
}
