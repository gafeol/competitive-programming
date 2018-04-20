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
char  s[MAXN];

int cnt[MAXN];

int main (){
	scanf(" %s", s);
	n = strlen(s);
	int ok = 1;
	cnt[s[0]]++;
	for(int a=1;a<n;a++){
		if(s[a] == 'a' && s[a-1] != 'a')
			ok = 0;
		if(s[a] == 'b' && s[a-1] == 'c')
			ok = 0;
		cnt[s[a]]++;
	}
	if(cnt['c'] != cnt['a'] && cnt['c'] != cnt['b'])
		ok = 0;
	if(cnt['a'] == 0 || cnt['b'] == 0)
		ok = 0;
	if(ok)
		puts("YES");
	else
		puts("NO");
}

