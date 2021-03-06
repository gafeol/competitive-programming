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

int n, m, k;

string w[MAXN];

unordered_map<int, unordered_map<char, int> > adj;
unordered_map<int, int> ult;

int deg;

void add(int i){
	int u = 0;
	for(char c: w[i]){
		if(adj[u].find(c) == adj[u].end())
			adj[u][c] = deg++;
		u = adj[u][c];
		ult[u] = i;
	}
}

string s;
unordered_map<int, int> wc, nxt;


int qry(){
	int u = 0;
	int i=0,tam = s.size();
	for(i=0;i<tam;i++){
		char c = s[i];
		if(adj[u].find(c) != adj[u].end()){
			wc[i] = ult[adj[u][c]];
			u = adj[u][c];
		}
		else{
			wc[i] = -1;
			u = deg + 1;
		}
	}
}

int main (){
	scanf("%d%d", &n, &m);
	deg = 1;
	for(int a=0;a<n;a++){
		char c;
		cin >> w[a];
	}
	for(int a=n-1;a>=0;a--)
		add(a);
	for(int a=0;a<m;a++){
		wc.clear();
		nxt.clear();
		cin >> s;
		qry();
		int tam = s.size();
		wc[tam] = -1;
		for(int i=tam-1;i>=0;i--){
			nxt[i] = i;
			if(wc[i] == wc[i+1])
				nxt[i] = nxt[i+1];
		}
		int ans = 1;
		for(int i=0;i<tam-1;i++){
			if(wc[i] == -1){
				ans++;
				continue;
			}
			int cus = 1 + w[wc[i]].size() - 1 - nxt[i];
			if(cus >= (nxt[i] - i + 1))
				ans++;
			else{
				ans += cus+(nxt[i]+1 != tam);
				i = nxt[i];
			}
		}
		printf("%d\n", ans);
	}
}

