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

int cnt[MAXN];

int main (){
	scanf("%d%d", &n, &k);
	for(int a=0;a<n;a++){ 
		char c;
		scanf(" %c", &c);
		cnt[c]++;
	}
	int res = 0;
	for(int a='a';k > 0 && a<='z';a++){
		if(cnt[a] > 0){
			res += a-'a'+1;
			k--;
			a ++;
			continue;
		}
	}
	if(k == 0){
		printf("%d\n", res);
	}
	else
		puts("-1");
}

