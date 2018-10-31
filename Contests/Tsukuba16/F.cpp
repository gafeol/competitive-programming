#include <bits/stdc++.h>
using namespace std;
#define pb push_back

#define fst first
#define snd second

typedef pair<string,  string> pss;
typedef pair<int,  int> pii;

const int MAXN = 310;

int n, m;
int mrk[112345];

set<pii> q;
map<pii, vector<int> > has;
map<string, int> ind;
vector<pii> r[112345];
vector<int> adj[MAXN], inv[MAXN];

queue<int> vis;

void upd(int a, int b);

bool add(int a, int b){
	pii p = pii(a, b);
	if(q.find(p) != q.end()) return false;
	//printf("add %d %d\n", a, b);
	q.insert(p);
	for(int x: has[p]){
		if(!mrk[x]){
			mrk[x] = true;
			vis.push(x); 	
		}
	}
	adj[a].pb(b);
	inv[b].pb(a);
	upd(a, b);
	return true;
}

void upd(int a, int b){
	for(int bef: inv[a])
		add(bef, b);
	for(int nxt: adj[b])
		add(a, nxt);
}

void fail(){
	puts("No");
	exit(0);
}

int main (){
	string ini, fim;
	cin >> ws >> ini >> ws >> fim;
	scanf("%d", &n);
	for(int a=0;a<n;a++){ 
		scanf("%d", &m);
		for(int b=0;b<m;b++){
			string A, B;
			cin >> ws >> A >> ws >> B;
			if(ind.find(A) == ind.end())
				ind[A] = ind.size();
			int ia = ind[A];
			if(ind.find(B) == ind.end())
				ind[B] = ind.size();
			int ib = ind[B];
			r[a].pb(pii(ia, ib));
			has[pii(ia, ib)].pb(a);
		}
	}
	if(ind.find(ini) == ind.end())
		ind[ini] = ind.size();
	int iini = ind[ini];
	if(ind.find(fim) == ind.end())
		ind[fim] = ind.size();
	int ifim = ind[fim];

	add(iini, ifim);
	
	while(!vis.empty()){
		int i = vis.front();
		//printf("vis %d\n", i);
		vis.pop();
		for(pii p: r[i])
			add(p.fst, p.snd);	
	}

	for(int a=0;a<ind.size();a++){
		if(q.find(pii(a, a)) != q.end())
			fail();
		for(int b=a+1;b<ind.size();b++)
			if(q.find(pii(a, b)) != q.end() && q.find(pii(b, a)) != q.end())
				fail();
	}
	puts("Yes");
}
