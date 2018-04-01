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

const int MAXN = 53;

int n[2], m, k;
char s[2][MAXN];

int dp[MAXN][MAXN][MAXN];

stack<int> st, sor;

vector<int> nxt[2][MAXN];

int ch[2][MAXN];

bool go(int i, int j, int res){
	if(res < 0) return 0;
	if(dp[i][j][res] != -1) return dp[i][j][res];
	if(i == n[0] && j == n[1]) return dp[i][j][res] = 1;
	dp[i][j][res] = 0;
	int ans = 0;
	if(j == n[1]){
		for(int ii:nxt[0][i])
			ans |= go(ii, j, res-ch[0][i]);
		dp[i][j][res] = ans;
		return ans;
	}
	if(i == n[0]){
		for(int jj:nxt[1][j])
			ans |= go(i, jj, res-ch[1][j]);
		dp[i][j][res] = ans;
		return ans;
	}
	if(!ch[0][i]){
		for(int ii:nxt[0][i])
			ans |= go(ii, j, res);
	}
	if(!ch[1][j]){
		for(int jj:nxt[1][j])
			ans |= go(i, jj, res);
	}
	if(ch[0][i] && ch[1][j]){
		for(int ii: nxt[0][i])
			ans |= go(ii, j, res-1);
		for(int jj: nxt[1][j])
			ans |= go(i, jj, res-1);
		for(int ii: nxt[0][i])
			for(int jj: nxt[1][j])
				ans |= go(ii, jj, res - (s[0][i] != s[1][j]));
	}
	dp[i][j][res] = ans;
	return ans;
}

int main (){
	for_tests(h, hh){
		memset(dp, -1, sizeof(dp));
		for(int t=0;t<2;t++){
			scanf(" %s", s[t]);
			n[t] = strlen(s[t]);
			for(int a=0;a<n[t];a++){
				nxt[t][a].clear();
				nxt[t][a].pb(a+1);
				if(s[t][a] == 'a' || s[t][a] == 'b') ch[t][a] = 1;
				else ch[t][a] = 0;
				if(s[t][a] == '(')
					st.push(a);
				else if(s[t][a] == ')'){
					int pos = st.top();
					if(!sor.empty() && sor.top() > st.top()){
						int x = sor.top();
						sor.pop();
						nxt[t][x].pb(a+1);
					}
					st.pop();
				}
				else if(s[t][a] == '*'){
					int pos = st.top();
					nxt[t][a].pb(pos+1);
					nxt[t][pos].pb(a+1);
				}
				else if(s[t][a] == '|'){
					int pos = st.top();
					sor.push(a);
					nxt[t][a].pop_back();
					nxt[t][pos].pb(a+1);
				}
			}
		}
		nxt[0][n[0]].clear();
		nxt[1][n[1]].clear();
		ch[0][n[0]] = 0;
		ch[1][n[1]] = 0;
		int pr = 0;
		for(int ans = 0;ans <= 50;ans++) {
			if(go(0, 0, ans)){ 
				pr = 1;
				printf("%d\n",ans);
				break;
			}
		}
		assert(pr);
	}
}

