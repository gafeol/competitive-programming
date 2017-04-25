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
int s[MAXN], v[MAXN];

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
	else if(i == 2)
		return 'Y';
	else
		return 'B';
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
		int mn = INT_MAX, imn;
		for(int a=0;a<6;a++){
			scanf("%d", &s[a]);
			v[a] = s[a];
			if(s[a] != 0){
				if(mn > s[a]){
					mn = s[a];
					imn = a;
				}
			}
		}
		printf("Case #%d: ", tt);
		if(go(imn)){
			for(int a=0;a<6;a++)
				s[a] = v[a];
			print(imn);
			printf("\n");
		}
		else
			puts("IMPOSSIBLE");
	}
}
