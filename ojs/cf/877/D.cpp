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

const int MAXN = 1123, INF = 0x3f3f3f3f;

int n, m, k;

int d[MAXN][MAXN];
char M[MAXN][MAXN];
int s[MAXN];

queue<pii> q;

bool valid(int i, int j){
	return (i >= 0 && j >= 0 && i < n && j < m && M[i][j] != '#');
}

set<int> lin[MAXN], col[MAXN];

int dist(int i, int j, int ii, int jj){
	return abs(ii - i) + abs(jj - j);
}
stack<pii> stl, stc;

void limpa(){
	while(!stl.empty()){
		lin[stl.top().fst].erase(stl.top().snd);
		stl.pop();
	}
	while(!stc.empty()){
		col[stc.top().fst].erase(stc.top().snd);
		stc.pop();
	}
}

void go(int i, int j){
	d[i][j] = 0;
	q.push(pii(i, j));
	lin[i].erase(j);
	col[j].erase(i);
	while(!q.empty()){
		i = q.front().fst;
		j = q.front().snd;
		debug("i %d j %d: %d\n", i, j, d[i][j]); 
		q.pop();
		auto it = lin[i].lower_bound(j);
		while(it != lin[i].end()){
			int ii = i,jj = *it;
			if(!valid(ii, jj) || dist(i, j, ii, jj) > k) break;
			d[ii][jj] = d[i][j] + 1;
			debug("	ii %d jj %d\n", ii, jj);
			q.push(pii(ii,jj));
			it++;
			stl.push(pii(i, jj));
			stc.push(pii(jj, i));
		}
		limpa();

		it = lin[i].lower_bound(j);
		while(it != lin[i].begin()){
			it--;
			int ii = i,jj = *it;
			if(!valid(ii, jj) || dist(i, j, ii, jj) > k) break;
			d[ii][jj] = d[i][j] + 1;
			debug("	ii %d jj %d\n", ii, jj);
			q.push(pii(ii,jj));
			stl.push(pii(i, jj));
			stc.push(pii(jj, i));
		}
		limpa();


		it = col[j].lower_bound(i);
		while(it != col[j].end()){
			int ii = *it, jj = j;
			if(!valid(ii, jj) || dist(i, j, ii, jj) > k) break;
			d[ii][jj] = d[i][j] + 1;
			debug("	ii %d jj %d\n", ii, jj);
			q.push(pii(ii,jj));
			it++;
			stc.push(pii(j, ii));
			stl.push(pii(ii, j));
		}
		limpa();

		it = col[j].lower_bound(i);
		while(it != col[j].begin()){
			it--;
			int ii = *it, jj = j;
			if(!valid(ii, jj) || dist(i, j, ii, jj) > k) break;
			d[ii][jj] = d[i][j] + 1;
			debug("	ii %d jj %d\n", ii, jj);
			q.push(pii(ii,jj));
			stc.push(pii(j, ii));
			stl.push(pii(ii, j));
		}
		limpa();
	}
}

int main (){
	memset(d, INF, sizeof(d));
	scanf("%d%d%d", &n, &m, &k);
	for(int a=0;a<n;a++){
		for(int b=0;b<m;b++){
			scanf(" %c", &M[a][b]); 
			lin[a].insert(b);
			col[b].insert(a);
		}
	}
	int i, j, ii, jj;
	scanf("%d %d %d %d", &i, &j, &ii, &jj);
	i--;
	j--;
	ii--;
	jj--;
	d[ii][jj] = 0;
	go(ii, jj);
	if(d[i][j] == INF){
		puts("-1");
		return 0;
	}
	printf("%d\n", d[i][j]);
}

