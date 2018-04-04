#include <bits/stdc++.h>
using namespace std;
#define fst first
#define snd second
typedef unsigned long long ull;
typedef long long ll;
typedef pair<char, char> pcc;
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

const int MAXN = 61;

int n, m, k;

pcc s[MAXN], aux[MAXN];

int ord[400], ordn[400], cres[400];

bool operator < (pcc &t, pcc &o){
	if(t.snd == o.snd){
		if(cres[t.snd])
			return (ord[t.fst] < ord[o.fst]);
		else
			return (ord[t.fst] > ord[o.fst]);
	}
	return (ordn[t.snd] < ordn[o.snd]);
}

vector<char> np;

int dp[MAXN][MAXN];

int go(int i, int lst){
	if(i == n+1) return 0;
	if(dp[i][lst] != -1) return dp[i][lst];
	dp[i][lst] = go(i+1, lst) + 1;
	if(s[lst] < s[i]) dp[i][lst] = min(dp[i][lst], go(i+1, i));
	return dp[i][lst];
}

int main (){
	scanf("%d", &n);
	int deg = 0;
	for(char ch = '2';ch <= '9';ch++)
		ord[ch] = deg++;
	ord['T'] = deg++;
	ord['J'] = deg++;
	ord['Q'] = deg++;
	ord['K'] = deg++;
	ord['A'] = deg++;
	np.pb('c');
	np.pb('d');
	np.pb('h');
	np.pb('s');
	for(int a=1;a<=n;a++){
		scanf(" %c%c", &s[a].fst, &s[a].snd);
		aux[a] = s[a];
	}
	int ans = INT_MAX;
	ordn[0] = -1;
	do{
		for(int a=0;a<np.size();a++)
			ordn[np[a]] = a;
		for(int bm=0;bm<(1<<4);bm++){
			cres['s'] = (bm&1);
			cres['h'] = (bm&2);
			cres['d'] = (bm&4);
			cres['c'] = (bm&8);
			for(int a=1;a<=n;a++)
				s[a] = aux[a];
			memset(dp, -1, sizeof(dp));
			ans = min(ans, go(1, 0));
			/*for(int t=0;t<4;t++)
				printf("%c %d ", np[t], cres[np[t]]);
			printf("ans %d\n", go(1, 0));
			*/
		}
	} while(next_permutation(np.begin(), np.end()));
	printf("%d\n", ans);

}

