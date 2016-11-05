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

const int MAXN = 2123456;

int n, m, k;
char s[MAXN];

int main (){
	scanf(" %s", s);
	int tam = strlen(s);
	int v =-1;
	int zer =-1, ult = -1;
	for(int a=0;a<tam;a++){
		if(zer == -1 && s[a] != '.' && s[a] != '0')
			zer = a;
		if(s[a] != '.' && s[a] != '0')
			ult = a;
		if(s[a] == '.')
			v = a;
	}
	if(v == -1){
		v = tam;
		s[tam] = '.';
		tam++;
	}
	debug("v %d zer %d ult %d\n", v, zer, ult); 
	if(zer == -1){
		puts("0");
		return 0;
	}
	int pot = 0;
	if(zer < v){
		while(v != zer+1){
			swap(s[v], s[v-1]);
			v--;
			pot++;
		}
	}
	else{
		while(v != zer){
			swap(s[v], s[v+1]);
			v++;
			pot--;
		}
	}
	zer =-1;
	for(int a=0;a<tam;a++){
		if(zer == -1 && s[a] != '.' && s[a] != '0')
			zer = a;
		if(s[a] != '.' && s[a] != '0')
			ult = a;
		if(s[a] == '.')
			v = a;
	}
	for(int a=zer;a<=ult;a++){
		printf("%c", s[a]);
	}
	if(pot != 0)
		printf("E%d\n", pot);
}
