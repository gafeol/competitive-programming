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

int main (){
	for_tests(t, tt){
		memset(s, 0, sizeof(s));
		int ok = 1;
		scanf("%d%d", &n, &k);
		int aa = n/2 - (n%2 == 0);
		for(int a=n/2;a<n;a++){
			if(a == n/2){
				s[a] = 'b';	
				s[aa] = 'b';
				aa--;
				continue;
			}
			char has = 0;
			if(a - k >= 0 && s[a-k] != 0){
				has = s[a-k];
			}
			if(s[aa] != 0){
				if(has != 0 && has != s[aa])
					ok = 0;
				has = s[aa];
			}
			if(has == 0)
				has = 'a';
			s[a] = has;
			s[aa] = has;
			aa--;
		}
		int ig = 1;
		for(int a=1;a<n;a++){
			if(s[a] != s[a-1]){
				ig = 0;
				break;
			}
		}
		if(ig)
			ok = 0;
		if(!ok)
			printf("impossible");
		else
			for(int a=0;a<n;a++)
				printf("%c", s[a]);
		puts("");
	}
}

