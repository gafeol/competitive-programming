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

int s[3], t1, t2, h;
int n, m, k;

int check(int i, int j){
	for(int a=0;a<3;a++){
		if(i < j){
			if(s[a] > i && s[a] < j)
				return 0;
		}
		else{
			if(s[a] > i || s[a] < j)
				return 0;
		}
	}
	return 1;
}

int main (){
	scanf("%d%d%d%d%d", &s[0], &s[1], &s[2], &t1, &t2);
	s[0] = (s[0]%12);
	s[0] *= 3600*5;
	s[0] += s[1]*60 + s[2];
	t1 = (t1%12);
	t2 = (t2%12);
	s[1] *= 3600;
	s[1] += s[2];
	s[2] *= 3600;
	for(int a=0;a<3;a++){
		debug("%d ", s[a]);
	}
	debug("\n");
	t1 *= 3600*5;
	t2 *= 3600*5;
	debug("t1 %d t2 %d\n", t1, t2);
	int ok = 1, ans = 0;
	ans = max(ans, check(t1, t2));
	ans = max(ans, check(t2, t1));
	debug("de t1 a t2 %d\n", check(t1, t2));
	debug("de t2 a t1 %d\n", check(t2, t1));

	if(ans)
		puts("YES");
	else
		puts("NO");
}

