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
int prof;
int dp[5123][512];
pii lst[5123][512];
int lstd[5123][512];

queue<pii> qu;

int main (){
	int som;
	scanf("%d%d", &k, &som);
	int mn = INT_MAX; 
	memset(dp, -1, sizeof(dp));
	for(int d=1;d<=min(som, 9);d++){
		lst[som-d][(d%k)] = {som, 0};
		lstd[som-d][(d%k)] = d;
		dp[som-d][(d%k)] = 1;
		qu.push({som-d, d%k});
	}
	while(!qu.empty()){
		pii to = qu.front();	
		qu.pop();
		int s = to.fst;
		int r = to.snd;
		for(int d=0;d<=9;d++){
			int ns = s-d, nr = (10*r + d)%k;
			if(ns >= 0 && dp[ns][nr] == -1){
				if(dp[ns][nr] == -1)
					qu.push({ns, nr});
				dp[ns][nr] = dp[s][r] + 1;
				lst[ns][nr] = {s, r};
				lstd[ns][nr] = d;
			}
		}
	}
	if(dp[0][0] == -1){
		puts("-1");
		return 0;
	}
	
	int s = 0, r = 0;
	stack<int> ans;
	while(s != som || r != 0){
		pii bef = lst[s][r];
		ans.push(lstd[s][r]);
		s = bef.fst;
		r = bef.snd;
	}
	while(!ans.empty()){
		printf("%d", ans.top());
		ans.pop();
	}
	puts("");

}

