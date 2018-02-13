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

const int MAXN = 612345;

int n, m, k;
char s[MAXN];

map<char, int> cnt;

int main (){
	for_tests(t, tt){
		scanf(" %s", s);
		n = strlen(s);
		cnt.clear();
		cnt[s[0]]++;
		cnt[s[1]]++;
		cnt[s[2]]++;
		int res = 0;
		for(int a=0;a<n-3;a++){
			cnt[s[a+3]]++;
			if(cnt['c'] == 1 && cnt['h'] == 1 && cnt['e'] == 1 && cnt['f'] == 1)
				res++;
			cnt[s[a]]--;
		}
		if(res){
			printf("lovely ");
			printf("%d\n", res);
		}
		else
			puts("normal");
	}
}

