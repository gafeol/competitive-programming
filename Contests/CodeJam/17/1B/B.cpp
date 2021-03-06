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

vector<int> res;

bool go(int pr){
	int ant = -1;
	s[pr]--;
	ant = pr;
	while(s[pr] != 0){
		int i = (pr+2)%6;
		int j = (pr+4)%6;
		if(s[i] < s[j])
			swap(i, j);
		s[i]--;
		if(s[i] < 0) return false;
		s[pr]--;
		ant = pr;
	}
	int i = (pr + 2)%6;
	int j = (pr + 4)%6;
	while(s[i] + s[j] > 0){
		if(ant == i){
			s[j]--;
			ant = j;
		}
		else if(ant == j){
			s[i]--;
			ant = i;
		}
		else{
			ant = (s[i] < s[j] ? i:j);
		}
	}
	return (s[i] == 0 && s[j] == 0);
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

void print(int pr){
	int ant = -1;
	printf("%c", ch(pr));
	s[pr]--;
	ant = pr;
	while(s[pr] != 0){
		int i = (pr+2)%6;
		int j = (pr+4)%6;
		if(s[i] < s[j])
			swap(i, j);

		printf("%c", ch(i));
		s[i]--;
		printf("%c", ch(pr));
		s[pr]--;
		ant = pr;
	}
	int i = (pr + 2)%6;
	int j = (pr + 4)%6;
	while(s[i] + s[j] > 0){
		if(ant == i){
			s[j]--;
			printf("%c", ch(j));
			ant = j;
		}
		else if(ant == j){
			s[i]--;
			printf("%c", ch(i));
			ant = i;
		}
		else{
			ant = (s[i] < s[j] ? i:j);
		}
	}
}

int main (){
	for_tests(t, tt){
		scanf("%d", &n);
		for(int a=0;a<6;a++){
			scanf("%d", &s[a]);
		}
		printf("Case #%d: ", tt);
		for(int i = 1;i < 6;i += 2){
			while(s[i] != 0){
				int tam = res.size();
				if(res.empty() || res[tam-1] != comp(i)){
					res.pb(comp(i));
					s[comp(i)]--;
					if(s[comp(i)] < 0){
						fodeu = 1;
						break;
					}
				}
				res.pb(i);
				s[i]--;
			}
			res.pb(comp(i));
			s[comp(i)]--;
			if(s[comp(i)] < 0){
				fodeu = 1;
				break;
			}
		}
		if(fodeu){
			puts("IM
		}
	}
}
