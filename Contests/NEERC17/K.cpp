
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

int n, m, k, A, B, f;
int cus[MAXN];
char s[26], v[26];

vector<int> adj[MAXN];

map<string, int> ind;

map<pii, int> dege;

int id(int u, int uu){
	if(u > uu) swap(u, uu);
	return dege[pii(u, uu)];
}

void add(int u, int uu){
	if(u > uu) swap(u, uu);
	if(dege.find(pii(u, uu)) == dege.end()){
		dege[pii(u, uu)] = m++;
	}
}

int main (){
	scanf("%d%d%d%d%d", &n, &A, &B, &k, &f);
	int deg = 0;
	int ult = -1;
	for(int a=0;a<n;a++){
		scanf(" %s %s", s, v);
		if(ind.find(s) == ind.end())
			ind[s] = deg++;
		if(ind.find(v) == ind.end())
			ind[v] = deg++;
		int i = ind[s];
		int j = ind[v];
		int val = A;
		if(i == ult) val = B;
		ult = j;
		add(i, j);
		cus[id(i, j)] += val;
	}
	sort(cus, cus+m);
	int ans =0 ;
	for(int a=m-1;a>=0;a--){
		if(k > 0 && cus[a] > f){
			ans += f;
			k--;
		}
		else
			ans += cus[a];
	}
	printf("%d\n", ans);

}

