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
char s[MAXN];

int main (){
	int tt = 1;
	while(1){
		scanf(" %s", s);
		if(s[0] == '-') break;
		int t = strlen(s);
		int cnt = 0, res = 0;
		for(int a=0;a<t;a++){
			if(s[a] == '{')
				cnt++;
			else
				cnt--;
			if(cnt < 0){
				res++;
				s[a] = '{';
				cnt+=2;
			}
		}
		cnt = 0;
		for(int a=t-1;a>=0;a--){
			if(s[a] == '{')
				cnt++;
			else
				cnt--;
			if(cnt > 0){
				res++;
				s[a] = '}';
				cnt-=2;
			}
		}
		printf("%d. %d\n", tt++, res);

	}
}
