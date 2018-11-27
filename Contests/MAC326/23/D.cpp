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

const int MAXN = 11234;

int n, m, k;
char s[30][30], pal[MAXN];

bool isvowel(char c){
	return (c == 'a' || c == 'e' || c == 'i' || c == 'u' || c == 'o');
}

int go(string p, int t){
	//cout << " go ( " << p << " " << t << " )"<<endl;
	if(p.size() == 1)
		return !isvowel(p[0]);
	
	string aux = "";
	for(int a=1;a<p.size();a+=2){
		aux += s[p[a-1]-'a'][p[a]-'a'];
	}
	if((p.size()&1))
		aux += p.back();
	if(go(aux, 1-t) == t)
		return t;

	aux = "";
	for(int a=p.size()-2;a>=0;a-=2){
		aux += s[p[a]-'a'][p[a+1]-'a'];
	}
	if((p.size()&1))
		aux += p.front();
	return go(aux, 1-t);
}
 
int main (){
	for_tests(t, tt){
		for(int a=0;a<26;a++){
			for(int b=0;b<26;b++){
				scanf(" %c", &s[a][b]);
			}
		}
		scanf(" %s", pal);	
		n = strlen(pal);
		if(go(pal, 0))
			puts("Marzo");
		else
			puts("Salah");
	}
}

