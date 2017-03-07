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
int cnt[MAXN], mrk[MAXN];
char s[MAXN]; 

set<pii> q;

vector<char> res;

int main (){
	scanf("%d", &n);
	scanf(" %s", s);
	int tam = strlen(s);
	for(int a=0;a<tam;a++){
		cnt[s[a]]++;
	}
	for(int a=0;a<n;a++){
		q.insert(pii((int)s[a], -a));
	}
	pii ant = pii(0, 1);
	for(int a=0;a<=tam-n;a++){
		pii top;
		if(-ant.snd < a){
			top = *q.begin();
			ant = top;
		}
		else
			top = ant;

		if(!mrk[-top.snd]){
			res.pb((char)top.fst);
			cnt[top.fst]--;
		}
		mrk[-top.snd] = 1;	
		
		q.erase(pii((int)s[a], -a));
		if(a != tam-n)q.insert(pii((int)s[a+n], -a-n));
	}
	int i = 0, tt = res.size();
	sort(res.begin(), res.end());
	for(int a = 'a';a <= 'z';a++){
		while(i < tt && res[i] <= a){
			printf("%c", res[i]);
			i++;
		}

		if(i == tt) break;

		while(cnt[a]){
			printf("%c", a);
			cnt[a]--;
		}
	}
	putchar('\n');
}
