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

int cnt[500];

int go(int k){
	for(int a='a';a<='z';a++)
		cnt[a] = 0;
	for(int a=0;a<k;a++)
		cnt[s[a]]++;
	for(int a=k;a<n;a++){
		if(cnt[s[a]] != 0)
			cnt[s[a]]++;
		cnt[s[a-k]] = max(0, cnt[s[a-k]]-1);
	}
	for(int a='a';a<='z';a++)
		if(cnt[a] != 0) return 1;
	return 0;
}

int main (){
	scanf(" %s", s);
	n = strlen(s);
	int i = 1, j = n;
	while(i < j){
		int m = (i + j)/2;
		if(go(m))
			j = m;
		else
			i = m+1;
	}
	printf("%d\n", i);
}

