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
int s[MAXN];
int fd = 0;

int M[210][210];

int deg[MAXN];

int ind[MAXN];

vector<int> adj[MAXN];

bool cmp(int a, int b){
	return deg[a] < deg[b];
}

vector<int> inter(pii pu, pii pv){	
	vector<int> vu = adj[M[pu.fst][pu.snd]];
	vector<int> vv = adj[M[pv.fst][pv.snd]];

	sort(vv.begin(), vv.end());


	
	vector<int> res;

	for(int x: vu)
		if(binary_search(vv.begin(), vv.end(), x))
			res.pb(x);	
	return res;
}


int check(bool b){
	if(!b){
		puts("-1");
		return 1;
	}
	return 0;
}

pii nxt(pii p, int x, int xx){
	printf("nxt %d %d \n", p.fst, p.snd);
	if(p.fst == x){
		p.snd--;
		if(p.snd < x){
			p.snd++;
			p.fst++;
		}
	}
	else if(p.fst == xx){
		p.snd++;
		if(p.snd > xx){
			p.snd = xx;
			p.fst--;
		}
	}
	else if(p.snd == x){
		p.fst++;	
	}
	else{
		p.fst--;
	}
	printf("aft %d %d \n", p.fst, p.snd);
	return p;
}

void f(int x, int xx){
	int u = M[x-1][x-1];
	sort(adj[u].begin(), adj[u].end(), cmp);
	if(check(adj[u].size() > 0))
		return 1;
	
	u = adj[u][0];

	M[x][x] = u; 
	deg[u] = INT_MAX;

	sort(adj[u].begin(), adj[u].end(), cmp);
	if(check(adj[u].size() > 2))
		return 0;
	M[x][x+1] = adj[u][0];
	deg[adj[u][0]] = INT_MAX;
	M[x+1][x] = adj[u][1];
	deg[adj[u][1]] = INT_MAX;

	pii ult = {x, x+1}, ult2 = {x, x};
	pii pos = {x+1, x};
	while((pos = nxt(pos, x, xx)) != pii(x, x+1)){
		vector<int> it = inter(ult, ult2);
		sort(it.begin(), it.end(), cmp);				
		if(check(it.size() > 0))
			return 1;
		M[pos.fst][pos.snd] = it[0];
		deg[it[0]] = INT_MAX;
	}
	return 0;
}

set<pii> q;

int main (){
	for_tests(t, tt){
		scanf("%d%d", &n, &m);
		for(int a=1;a<=n*n;a++)
			ind[a] = a;
		if(n == 1){
			if(check(m > 0))
				continue;
			puts("1");
			continue;
		}
		
		for(int a=0;a<m;a++){
			int i, j;
			scanf("%d%d", &i, &j);
			adj[j].pb(i);
			deg[j]++;
			adj[i].pb(j);
			deg[i]++;
			if(i > j)
				swap(i, j);
			q.insert({i, j});
		}
		sort(ind+1, ind+n*n+1, cmp);
		
		int u = ind[1];
		deg[u] = INT_MAX;
		M[1][1] = u;
		sort(adj[u].begin(), adj[u].end(), cmp);
		if(check(adj[u].size() > 2))
			continue;
		M[1][2] = adj[u][0];
		deg[adj[u][0]] = INT_MAX;
		M[2][1] = adj[u][1];
		deg[adj[u][1]] = INT_MAX;

		pii ult = {1, 2}, ult2 = {1, 1};
		pii pos = {2, 1};
		while((pos = nxt(pos, 1, n)) != pii(1, 2)){
			vector<int> it = inter(ult, ult2);
			sort(it.begin(), it.end(), cmp);				
			if(check(it.size() > 0)){
				fd = 1;
				break;
			}
			M[pos.fst][pos.snd] = it[0];
			deg[it[0]] = INT_MAX;
		}
		if(fd)
			continue;

		for(int d=2;d<=n/2;d++){
			if(f(d, n-d+1)){
				fd = 1;
				break;
			}
		}
		if(fd) continue;

		int vi[] = {0, 0, 0, 0, 1, 2, -1, -2, 1, -1, 1, -1};
		int vj[] = {2, 1, -2, -1, 0, 0, 0, 0, 1, 1, -1, -1};
		for(int a=1;a<=n;a++){
			for(int b=1;b<=n;b++){
				for(int d=0;d<12;d++){
					int aa = a + vi[a];
					int bb = b + vj[b];
					int x = M[aa][bb];
					int y = M[a][b];
				}
			}
		}

		for(int a=1;a<=n;a++){
			for(int b=1;b<=n;b++){
				printf("%d ", M[a][b]);
			}
			puts("");
		}
	}
}

