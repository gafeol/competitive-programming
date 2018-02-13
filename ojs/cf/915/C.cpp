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

const int MAXN = 21;
char n[MAXN], m[MAXN];

bool cmp(char a, char b){
	return a > b;
}

int cnt[500];

char ans[100];
int tam;

int go(int i, int l){	
	if(i == tam) return 1;
	if(l){
		for(char a='9';a>='0';a--){
			if(!cnt[a]) continue;
			cnt[a]--;
			go(i+1, l);
			ans[i] = a;
			return 1;
		}
	}
	else{
		for(char a=m[i];a>='0';a--){
			if(!cnt[a]) continue;
			cnt[a]--;
			if(!go(i+1, (a < m[i]))){
				cnt[a]++;
			}
			else{
				ans[i] = a;
				return 1;
			}
		}
	}
	return 0;
}

int main (){
	scanf(" %s %s", n, m);
	tam = strlen(n);
	if(strlen(n) < strlen(m)){
		sort(n, n+tam, cmp); 
		for(int a=0;a<tam;a++){
			ans[a] = n[a];
		}
	}
	else{
		for(int a=0;a<tam;a++){
			cnt[n[a]]++;
		}
		go(0, 0);
	}
	for(int a=0;a<tam;a++){
		printf("%c", ans[a]);
	}
}

