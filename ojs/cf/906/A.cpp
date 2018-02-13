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

const int MAXN = 412;

int n, m, k;
char s[200000];

int d = 0;
int mrk[MAXN];

int has[MAXN];

int main (){
	scanf("%d", &n);
	for(int a='a';a<='z';a++)
		mrk[a] = 1;
	int res = 0;
	for(int a=0;a<n;a++){
		char c;
		scanf(" %c %s", &c, s);
		if(a == n-1) break;
		if(d && c != '.')
			res++;
		int tam = strlen(s);

		for(int a='a';a<='z';a++)
			has[a] = 0;
		
		for(int i=0;i<tam;i++){
			has[s[i]] = 1;
		}
		int cnt = 0;
		for(int a='a';a<='z';a++){
			if(c == '!'){
				if(!has[a])
					mrk[a] = 0;
			}
			else {
				if(has[a])
					mrk[a] = 0;
			}
			cnt += (mrk[a] != 0);
		}
		if(cnt == 1) d = 1;
	}
	printf("%d\n", res);
}

