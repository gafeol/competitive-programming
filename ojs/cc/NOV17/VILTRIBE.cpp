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
int nxt[MAXN];

int main (){
	for_tests(t, tt){
		scanf(" %s", s);
		n = strlen(s);
		int ult = 0;
		int cnt[3];
		memset(cnt, 0, sizeof(cnt));
		for(int a=n-1;a>=0;a--){
			if(s[a] == 'A')
				ult = 1;
			else if(s[a] == 'B')
				ult = 2;
			nxt[a] = ult;
		}
		ult = 0;
		for(int a=0;a<n;a++){
			if(s[a] == 'A')
				ult = 1;
			else if(s[a] == 'B')
				ult = 2;
			if(ult == nxt[a])
				cnt[ult]++;
		}
		printf("%d %d\n", cnt[1], cnt[2]);
	}
}
