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

const int MAXN = 312345;

int n, m, k;
int mrk[MAXN];

vector<int> s, v;
string str, str2;

char c;

map<string, int> ind;
pii val[MAXN];
unordered_map<int, int> best;
vector<int> syn[MAXN];
vector<int> inv[MAXN];

void dfs(int u, int ini){
	mrk[u] = 1;
	best[u] = ini;
	for(int nxt: inv[u]){
		if(!mrk[nxt])
			dfs(nxt, ini);
	}
}

/*
void go(int u){
	if(best.find(u) != best.end()) return ;
	best[u] = u;
	if(syn.find(u) == syn.end()) return ;

	for(int sin: syn[u]){
		go(sin);	
		if(val[best[u]] > val[best[sin]])
			best[u] = best[sin];
	}
}
*/

bool cmp(int a, int b){
	return val[a] < val[b];
}

int main (){
	scanf("%d", &n);
	scanf("%*d");
	int deg = 1;
	for(int a=0;a<n;a++){
		int cnt = 0;
		while(1){
			c = getchar();
			if(c == ' ' || c == '\n'){
				if(ind.find(str) == ind.end()){
					ind[str] = deg++;
					v.pb(deg-1);
				}
				s.pb(ind[str]);
				val[ind[str]] = pii(cnt, str.size());
			//	cout << " " << str << " ind " << ind[str] << endl;
				str.clear();
				break;
			}
			c = tolower(c);
			if(c == 'r')
				cnt++;
			str.pb(c);		
		}
	}
	scanf("%d", &m);
	scanf("%*d");
	for(int a=0;a<m;a++){
		int cnt = 0;
		while(1){
			c = getchar();
			if(c == ' ' || c == '\n'){
				if(ind.find(str) == ind.end()){
					ind[str] = deg++;
					v.pb(deg-1);
				}
				val[ind[str]] = pii(cnt, str.size());
			//	cout << " " << str << " ind " << ind[str] << endl;
				break;
			}
			c = tolower(c);
			if(c == 'r')
				cnt++;
			str.pb(c);		
		}
		cnt = 0;
		while(1){
			c = getchar();
			if(c == ' ' || c == '\n'){
				if(ind.find(str2) == ind.end()){
					ind[str2] = deg++;
					v.pb(deg-1);
				}
				val[ind[str2]] = pii(cnt, str2.size());
			//	cout << " " << str2 << " ind " << ind[str2] << endl;
				break;
			}
			c = tolower(c);
			if(c == 'r')
				cnt++;
			str2.pb(c);		
		}
		syn[ind[str]].pb(ind[str2]);
		inv[ind[str2]].pb(ind[str]);
		str.clear();
		str2.clear();
	}
	ll tam = 0;
	ll numr = 0;
	sort(v.begin(), v.end(), cmp);
	for(int u: v){
		if(!mrk[u])
			dfs(u, u);
	}
	for(int pal: s){
		numr += val[best[pal]].fst;
		tam += val[best[pal]].snd;
	}
	printf("%lld %lld\n", numr, tam);

}
