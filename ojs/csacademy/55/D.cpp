
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
int s[MAXN];
int cus[MAXN][2];

char **M;

int ceil(int a, int b){
	return (a/b + (a%b != 0));
}

int cost(int i, int j, int ii, int jj){
	if(j == jj || i == ii)
		return (int)(M[i][j] != M[ii][jj]);
	return (int)((M[i][jj] != M[i][j]) + (M[ii][j] != M[i][j]) + (M[ii][jj] != M[i][j]));
}

multiset<int> q;

int main (){
	scanf("%d%d%d", &n, &m, &k);
	M = (char**)malloc(n*sizeof(char*));
	for(int a=0;a<n;a++){
		M[a] = (char *)malloc(m*sizeof(char));
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			scanf(" %c", &M[i][j]);
		}
	}
	int ans = 0;
	int um = -1;
	for(int j=0;j<ceil(m, 2);j++){
		int jj = m - j - 1;
		for(int i=0;i<n;i++){
			cus[j][0] += (M[i][j] != M[i][jj]);
		}
		for(int i=0;i<ceil(n, 2);i++){
			int ii = n - 1 - i;
			cus[j][1] += min(min(cost(i, j, ii, jj), cost(i, jj, ii, j)),
								min(cost(ii, j, i, jj), cost(ii, jj, i, j)));
		}
		ans += cus[j][0];
		debug("j %d cus[0] %d cus[1] %d\n", j, cus[j][0], cus[j][1]);
		if((m&1) && j == ceil(m,2)-1){
			um = cus[j][1] - cus[j][0];
			continue;
		}
		q.insert(cus[j][1] - cus[j][0]);
	}
	int kk = k;
	int res = ans; 
	int mn = INT_MAX;
	stack<int> tirei;
	
	if(um != -1){
		k--;
		ans += um;
		while(k > 0){
			ans += *q.begin();
			k -= 2;
			tirei.push(*q.begin());
			q.erase(q.begin());
		}
		mn = min(mn, ans);
	}
	
	k = kk;
	ans = res;
	while(!tirei.empty()){
		q.insert(tirei.top());
		tirei.pop();
	}

	while(k > 0 && !q.empty()){
		ans += *q.begin();
		k -= 2;
		q.erase(q.begin());
	}
	if(k <= 0)
		mn = min(ans, mn);

	printf("%d\n", mn);
}

