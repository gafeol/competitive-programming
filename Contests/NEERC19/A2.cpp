#include <bits/stdc++.h>
using namespace std;
#define fst first
#define snd second
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;
#define pb push_back
#define for_tests(t, tt) int t; scanf("%d", &t); for(int tt = 1; tt <= t; tt++)

template <typename T> void write(ostream& out, T t) {
	out << t << "\n";
}
template <typename T, typename... Args>
void write(ostream& out, T t, Args... args) {
	out << t << ' ';
	write(out, args...);
}

template <typename... Args>
void debug(Args... args) {
	#ifdef LOCAL
		write(cerr, args...);
	#endif
}


template<typename T> inline T abs(T t) { return t < 0? -t : t; }
const ll modn = 1000000007;
inline ll mod(ll x) { return x % modn; }

const int INF = 0x3f3f3f3f;

int n, m, k;
int dp[5123][512];

int go(int s, int r){
	if(s < 0) return INF;
	if(s == 0 && r == 0)
		return dp[s][r] = 0;
	if(dp[s][r] != -1) 
		return dp[s][r];

	dp[s][r] = INF;
	for(int d=0;d<=9;d++)
		dp[s][r] = min(dp[s][r], 1 + go(s-d, (r*10 + d)%k));
	return dp[s][r];
}

int S;

void re(int s, int r){
	assert(s >= 0);
	if(s == 0 && r == 0)
		return ;

	for(int d=0;d<=9;d++){
		if(1 + go(s-d, (r*10 + d)%k) == go(s, r)){
			printf("%d", d);
			S += d;
			re(s-d, (r*10 + d)%k);
			return ;
		}
	}
}

int main (){
	int som;
	srand(time(NULL));
	while(1){
		k = rand()%501;
		som = rand()%5001;
		printf("k %d som %d\n", k, som);
		int mn = INT_MAX;
		memset(dp, -1, sizeof(dp));
		for(int d=1;d<=9;d++){
			mn = min(mn, 1+go(som-d, (d%k)));
		}
		if(mn >= INF){
			puts("-1");
			continue;
		}
		for(int d=1;d<=9;d++){
			if(mn == 1+go(som-d, (d%k))){
				printf("%d", d);
				S += d;
				re(som-d, (d%k));
				break;
			}
		}
		puts("");
		assert(S == som);
	}
}

