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
char s[40];

int cnt[40];

int main (){
	for_tests(t, tt){
		scanf("%d", &k);
		scanf(" %s", s);
		int ans = 0;
		int tam = strlen(s);
		int res = 0, dmg = 1;
		int count = 1;
		for(int a=0;a<tam;a++){
			cnt[a] = 0;
			if(s[a] == 'S')
				res += dmg;
			else{
				dmg *= 2;
				cnt[a] = count++;
			}
		}
		for(int a=tam-1;a>=0;a--){
			if(s[a] == 'C' && s[a+1] == 'S'){
				int b = a;
				while(res > k && b < tam && s[b+1] == 'S'){
					res += -(1<<cnt[b]) + (1<<(cnt[b]-1));
					swap(s[b], s[b+1]);
					swap(cnt[b], cnt[b+1]);
					b++;
					ans++;
				}
			}
		}
		printf("Case #%d: ", tt);
		if(res <= k)
			printf("%d\n", ans);
		else
			puts("IMPOSSIBLE");
	}
}

