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
int s[MAXN], v[MAXN];
int mrk[MAXN];

int main (){
	scanf("%d", &n);
	for(int a=0;a<n;a++){
		scanf("%d", s+a);
	}
	for(int a=0;a<n;a++){
		scanf("%d", v+a);
	}
	for(int i=0;i<n;i++){
		mrk[s[i]]++;
	}
	int falta = 0;
	for(int i=1;i<=n;i++){
		if(mrk[i] == 0)
			falta = i;
	}
	for(int i=0;i<n;i++){
		if(mrk[s[i]] == 1)
			continue;
		int old = s[i];
		s[i] = falta;
		int err = 0;
		for(int j=0;j<n;j++){
			if(v[j] != s[j])
				err++;
		}
		if(err == 1){
			for(int a=0;a<n;a++){
				printf("%d ", s[a]);
			}
			return 0;
		}
		s[i] = old;
	}
}
