
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

#define prev asdads

const int MAXN = 2123;

int n, m, k;
int s[MAXN];

int pot[MAXN];

vector<char> res[MAXN];

map<int, int> prev[11];
map<int, char> op[11];

void solve(int i, int sum){
	int val = sum;
	while(i > 0){
		res[sum].pb(op[i][val]);
		val = prev[i][val];
		i--;
	}
}

void dfs(int i, int sum){
	if(sum >= 1 && sum <= 1000 && res[sum].size() == 0)
		solve(i, sum);
	if(i == 10) return ;
	prev[i+1][sum + pot[i]] = sum;
	op[i+1][sum+pot[i]] = '+';
	dfs(i+1, sum+pot[i]);

	prev[i+1][sum - pot[i]] = sum;
	op[i+1][sum-pot[i]] = '-';
	dfs(i+1, sum-pot[i]);

	prev[i+1][sum] = sum;
	op[i+1][sum] = '0';
	dfs(i+1, sum);
}



int main (){
	pot[0] = 1;
	for(int a=1;a<=10;a++){
		pot[a] = 3*pot[a-1];
	}
	dfs(0, 0);
	for_tests(t, tt){
		scanf("%d", &n);
		for(char c: res[n]){
			printf("%c", c);
		}
		puts("");
	}
}

