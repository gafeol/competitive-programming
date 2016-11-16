#include <bits/stdc++.h>
using namespace std;
#define fst first
#define snd second
typedef unsigned long long ull;
typedef long long ll;
typedef pair<ll, ll> pii;
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

const int MAXN = 512345;

int n, m;

pii k, s[MAXN];
char c[MAXN];
vector<pii> diag, quad;

int prox[8];

#define UR 0
#define UP 1
#define UL 2
#define LE 3
#define DL 4
#define DO 5
#define DR 6
#define RI 7

void check(int a){
	int i = k.fst, j = k.snd;
	int ii = s[a].fst, jj = s[a].snd;
	if(i + j == ii + jj){
		if(ii < i){
			//UR
			debug("UR %d\n", a);
			if(prox[UR] == -1 || ii > s[prox[UR]].fst)
				prox[UR] = a;
		}
		else{
			debug("dl %d\n", a);
			//DL
			if(prox[DL] == -1 || ii < s[prox[DL]].fst)
				prox[DL] = a;
		}
	}
	if(i - j == ii - jj){
		if(ii < i){
			//UL
			debug("ul %d\n", a);
			if(prox[UL] == -1 || ii > s[prox[UL]].fst)
				prox[UL] = a;
		}
		else{
			//DR
			debug("dr %d\n", a);
			if(prox[DR] == -1 || ii < s[prox[DR]].fst)
				prox[DR] = a;
		}
	}
	if(i == ii){
		if(jj < j){
			//LE
			debug("l %d\n", a);
			if(prox[LE] == -1 || jj > s[prox[LE]].snd){
				prox[LE] = a;
			}
		}
		else{
			//RI
			debug("r %d\n", a);
			if(prox[RI] == -1 || jj < s[prox[RI]].snd){
				prox[RI] = a;
			}
		}
	}
	if(j == jj){
		if(ii < i){
			//U
			debug("u %d\n", a);
			if(prox[UP] == -1 || ii > s[prox[UP]].fst)
				prox[UP] = a;
		}
		else{
			debug("d %d\n", a);
			if(prox[DO] == -1 || ii < s[prox[DO]].fst)
				prox[DO] = a;
		}
	}
}

int main (){
	scanf("%d", &n);
	memset(prox, -1, sizeof(prox));
	scanf("%lld %lld", &k.fst, &k.snd);
	for(int a=0;a<n;a++){
		scanf(" %c %lld %lld", &c[a], &s[a].fst, &s[a].snd);
		check(a);
	}
	int fodeu = 0;
	for(int a=0;a<8;a++){
		if(prox[a] == -1) continue;
		debug("dir %d - %c %lld %lld\n",a, c[prox[a]], s[prox[a]].fst, s[prox[a]].snd); 
		if(c[prox[a]] == 'Q'){
			fodeu = 1;
			break;
		}
		if(c[prox[a]] == 'R' && (a&1)){
			fodeu = 1;
			break;
		}
		if(c[prox[a]] == 'B' && !(a&1)){
			fodeu = 1;
			break;
		}
	}
	if(fodeu)
		puts("YES");
	else
		puts("NO");
}
