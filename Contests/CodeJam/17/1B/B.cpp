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
int s[10], v[10];

inline int cp(int i){
	return (i + 3)%6;
}

inline char ch(int i){
	if(i == 0)
		return 'R';
	else if(i == 1)
		return 'O';
	else if(i == 2)
		return 'Y';
	else if(i == 3)
		return 'G';
	else if(i == 4)
		return 'B';
	else
		return 'V';
}

int main (){
	for_tests(t, tt){
		int cntz = 0;
		for(int a=0;a<6;a++){
			scanf("%d", &s[a]);	
			v[a] = s[a];
			if(!s[a])
				cntz++;
		}
		printf("Case #%d: ", tt);
		if(cntz == 5){
			puts("IMPOSSIBLE");
			continue;
		}
		if(cntz == 4){
			int aux = 0, j;
			for(int i=1;i<6;i+=2){
				if(s[i]){
					aux++;
					j = i;
				}
			}
			if(aux > 1){
				puts("IMPOSSIBLE");
				continue;
			}
			int val[2], ind[2], deg = 0;
			for(int i=0;i<6;i++){
			if(s[i]){
					val[deg] = v[i];
					ind[deg++] = i;
				}
			}
			if(val[0] != val[1]){
				puts("IMPOSSIBLE");
				continue;
			}

			int i = 0;
			while(val[i] != 0){
				printf("%c", ch(ind[i]));
				val[i]--;
				i = i^1;
			}
			continue;
		}
		int fodeu = 0;
		for(int i=1;i<6;i+=2){
			if(s[i] != 0 && s[cp(i)] <= s[i]){
				puts("IMPOSSIBLE");
				fodeu = 1;
				break;
			}
			s[cp(i)] -= s[i];
		}

		if(fodeu) continue;

		int soma=0, mx=INT_MIN;
		for(int i = 0;i < 6;i+=2){
			soma += s[i];
			mx = max(mx, s[i]);
		}
		if(mx > soma-mx){
			puts("IMPOSSIBLE");
			continue;
		}
	}
}
