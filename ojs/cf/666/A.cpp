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
char s[MAXN];
int tam;
int dp[MAXN][4];

vector<pair<pair<char, char>, char> > ans;
map<pair<pair<char, char>, char>, int > mrk;

bool check(int t, int u, int i){
	if(t != u)
		return true;
	if(t == 2)
		return (s[i] != s[i-2] || s[i+1] != s[i-1]);

	return (s[i] != s[i-3] || s[i+1] != s[i-2] || s[i+2] != s[i-1]);
}

pair<pair<char, char>, char> con(char a, char b, char c){
	return make_pair(make_pair(a, b), c);
}

void add(pair<pair<char, char>, char> p){
	if(mrk.find(p) == mrk.end()){
		mrk[p] = 1;
		ans.pb(p);
	}
}

int go(int i, int p){
	if(i >= tam-1) return (i == tam);
	if(dp[i][p] != -1)
		return dp[i][p];

	int &r = dp[i][p];
	r = 0;

	if(check(2, p, i) && go(i+2, 2)){
		add(con(s[i], s[i+1], ' '));
		r = 1;
	}
	if(check(3, p, i) && go(i+3, 3)){
		add(con(s[i], s[i+1], s[i+2]));
		r = 1;
	}

	return r;
}

int main (){
	memset(dp, -1, sizeof(dp));
	scanf(" %s", s);
	tam = strlen(s);
	if(tam <= 5){
		puts("0");
		return 0;
	}
	for(int a=5;a<tam;a++)
		go(a, 0);	

	sort(ans.begin(), ans.end());
	printf("%d\n", ans.size());
	for(pair<pair<char, char>, char> p: ans){
		printf("%c%c%c\n", p.fst.fst, p.fst.snd, p.snd);
	}
}
