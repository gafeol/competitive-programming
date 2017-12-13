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

int p[2];
int ok;

int main (){
	while(scanf(" %s", s) != EOF){
		ok = 1;
		memset(p, 0, sizeof(p));
		for(int i=0;i<10;i++){
			p[0] += (s[i*2] == '1');
			if(i < 5){
				if(p[0] > p[1] + 5 - i){
					printf("TEAM-A %d\n", i*2+ 1);
					ok = 0;
					break;
				}
				if(p[1] > p[0] + 4 - i){
					printf("TEAM-B %d\n", i*2+ 1);
					ok = 0;
					break;
				}
			}
			p[1] += (s[i*2+1] == '1');
			if(i < 5){
				if(p[0] > p[1] + 4 - i){
					printf("TEAM-A %d\n", i*2+1 + 1);
					ok = 0;
					break;
				}
				if(p[1] > p[0] + 4 - i){
					printf("TEAM-B %d\n", i*2+1 + 1);
					ok = 0;
					break;
				}
			}
			if(!ok) break;
			if(i >= 5 && p[0] != p[1]){
				int a = 0, b = 1;
				if(p[a] < p[b]) swap(a, b);
				printf("TEAM-%c %d\n", "AB"[a], i*2+1 + 1);
				ok = 0;
				break;
			}
		}
		if(ok)
			puts("TIE");
	}
}

