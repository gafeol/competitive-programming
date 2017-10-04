
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
int s[MAXN];
int dif[MAXN];

int main (){
	scanf("%d", &n);
	for(int a=0;a<n;a++){
		scanf("%d", &s[a]);
	}
	sort(s, s+n);
	int suma = 0, sumb = 0;
	for (int i=0;i<n;i+=2) {
		suma += s[i+1];
		sumb += s[i];
		dif[i/2] = (s[i+1]-s[i]);
	}
	if (suma <= sumb) {
		printf("-1\n");
		return 0;
	}
	sort(dif, dif+n/2);
	int resp = 0;
	for (int i=0;i<n/2;i++) {
		suma -= dif[i];
		sumb += dif[i];
		if (suma > sumb) resp++;
		else break;
	}
	printf("%d\n", resp);
}

