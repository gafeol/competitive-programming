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

const int MAXN = 112*112*3*2;

int n, m, k;

vector<tuple<int, int, int> > s;
int nc, visc;
int cy[MAXN], vis[MAXN], mn[MAXN], idd[MAXN], rep[MAXN];
vector<int> adj[MAXN];
stack<int> q;

void reset(int n){
	while(!q.empty()) q.pop();
	nc = visc = 0;
	/* atencao para zerar o valor de TODAS variaveis */
	for(int a=0;a<=2*n;a++){
		adj[a].clear();
		cy[a] = -1;
		vis[a] = 0;
	}
}


int tarjan(int u){
	q.push(u);
	vis[u] = 1;
	idd[u] = visc++;
	mn[u] = idd[u];
	for(int nxt: adj[u]){
		if(!vis[nxt])
			mn[u] = min(mn[u], tarjan(nxt));
		else if(cy[nxt] == cy[u])
			mn[u] = min(mn[u], idd[nxt]);
	}
	if(mn[u] == idd[u]){
		rep[nc] = u;
		cy[u] = nc++;
		while(q.top() != u){
			cy[q.top()] = cy[u];
			q.pop();
		}
		q.pop();
	}
	return mn[u];
}

int id(int u, int v, int d, int t){
    return ((u*n + v)*3 + d)*2 + t;
}

void add_edge(int u, int v){
	adj[u].pb(v);
}

void seta(int u){
	add_edge((u^1), u);
}

//    /subseteq /eq     /inter eh zero
const int C = 0, EQ = 1, IN = 2;

void init(){
    for(int i=0;i<n;i++){
        seta(id(i, i, C, true));
        seta(id(i, i, EQ, true));
        seta(id(i, i, IN, false));
        for(int j=0;j<n;j++){
            if(j == i) 
                continue;
            // se i subseteq de j
            //          entao inter NAO eh zero
            //add_edge(id(i, j, C, true), id(i, j, IN, false));
            //add_edge(id(i, j, C, true), id(j, i, IN, false));

            // se i NAO eh subseteq de j
            //          entao nao pode ser igual
            add_edge(id(i, j, C, false), id(i, j, EQ, false));

            // se i eq j
            //          entao inter NAO eh zero
            //add_edge(id(i, j, EQ, true), id(i, j, IN, false));
            //          entao i subseteq j
            add_edge(id(i, j, EQ, true), id(i, j, C, true));
            //          entao j subseteq i
            add_edge(id(i, j, EQ, true), id(j, i, C, true));
            //          entao j = i
            add_edge(id(i, j, EQ, true), id(j, i, EQ, true));
            // se i NAO eq j
            //          entao j NAO eq i
            add_edge(id(i, j, EQ, false), id(j, i, EQ, false));

            
            // se i IN j == 0
            //          entao j IN i  == 0 
            add_edge(id(i, j, IN, true), id(j, i, IN, true));
            //          entao i EQ j  false
            //add_edge(id(i, j, IN, true), id(i, j, EQ, false));
            //          entao j EQ i  false
            //add_edge(id(i, j, IN, true), id(j, i, EQ, false));
            //          entao i C j false
            //add_edge(id(i, j, IN, true), id(i, j, C, false));
            //add_edge(id(i, j, IN, true), id(j, i, C, false));
            // se i IN j != 0
            //          entao j IN i != 0
            add_edge(id(i, j, IN, false), id(j, i, IN, false));
        }
    }
}

bool go(int ate, int n = n*n*3){
    reset(n);
    init();

    for(int a=0;a<=ate;a++){
        int op, i, j;        
        tie(op, i, j) = s[a];
        if(op == 0){ // Xi \subseteq  Xj
            seta(id(i, j, C, true));
        }
        else if(op == 1){ // Xi = Xj
            seta(id(i, j, EQ, true));  
        }
        else if(op == 2){ // xi != xj
            seta(id(i, j, EQ, true));  
            seta(id(i, j, EQ, false));
            add_edge(id(i, j, C, true), id(j, i, C, false));
            add_edge(id(j, i, C, true), id(i, j, C, false));
        }
        else if(op == 3){ // xi inter xj = 0
            seta(id(i, j, IN, true));
        }
        else { // xi inter xj != 0
            seta(id(i, j, IN, false));
        }
    }
	for(int a=0;a<2*n;a++)
		if(!vis[a])
			tarjan(a);
	for(int a=0;a<2*n;a+=2){
		if(cy[a] == cy[a+1]){
			return false;
		}
	}
    return true;
}

int main (){
    while(scanf("%d%d", &n, &m) != EOF && n+m){
        s.clear();
        for(int a=0;a<m;a++){
            int op, i, j;
            scanf("%d%d%d", &op, &i, &j);
            op--;
            i--;
            j--;
            s.pb({op, i, j});
        }
        int i = 0, j = m-1;
        while(i < j){
            int m = (i + j + 1)/2;
            if(go(m)){
                i = m;
            }
            else{
                j = m-1;
            }
        }
        printf("%d\n", i+1);
    }
}

