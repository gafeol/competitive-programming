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
#define debug(args...) //fprintf(stderr,args)
#else
#define debug(args...)
#endif //ONLINE_JUDGE
template<typename T> inline T abs(T t) { return t < 0? -t : t; }
const ll modn = 1000000007;
inline ll mod(ll x) { return x % modn; }

const int MAXN = 212345;

int n, m, k;
char s[MAXN];
int nxt;
ll res;

int readn(int i){
	int j = i;
	while(j < n && ((s[j] >= '0' &&  s[j] <= '9') || (s[j] >= 'A' && s[j] <= 'Z')))
		j++;	
	nxt = j;
	j--;
//	debug("nxt %d\n", nxt);
	ll fc = 1;
	ll ind = 1;
	ll ans = 0;
	while(j >= i){
//		debug("le %d\n", (s[j] - '0'));
		if(s[j] >= '0' && s[j] <= '9')
			ans += fc*(s[j] - '0');
		else
			ans += fc*(s[j] - 'A' + 10);
		j--;
		ind++;
		fc *= ind;
	}
	return ans;
}


void print(){
	ll f = 1;
	ll ind = 1;
	while(f <= res){
		ind++;
		f *= ind;
	}
	f /= ind;
	ind--;
//	debug("res %lld", res);  
	if(res == 0){
		printf("0");
		return;
	}
	while(ind > 0){
		if((res/f) > 9){
			debug("(char %lld)", res/f);
			printf("%c", (char)((res/f)-10+'A'));
		}
		else
			printf("%lld", res/f);
		res -= (res/f)*f;
		f /= ind;
		ind--;
	}
}

int main (){
	scanf(" %s", s);
	int i = 0;
	n = strlen(s);
	ll sig = 1;
	while(i < n){
		if(i != 0){
			if(s[i] == '+')
				sig = 1;
			else
				sig = -1;
			i++;
		}
		ll x = readn(i);
		debug("x %lld\n", x);
		i = nxt;
		res += sig*x;	
		debug("res %lld\n", res);
	}
	print();
	printf("\n");
}
