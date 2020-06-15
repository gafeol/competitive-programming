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

const int MAXN = 112;

int w, h;
char M[MAXN][MAXN];

// maximum node and edge constraints
const int N = 11234;
const int E = 8*N;
vector<pii> adj[2][N];
int cnt;
int temp_path[E], final_path[E], tsz, fsz;
int mrk[E];

void add_edge(int t, int a, int b){
	// undirected edge
    //mprintf("Adds edge (%d %d) - (%d %d) tipo %d\n", a/(h+1), a%(h+1), b/(h+1), b%(h+1), t);
	adj[t][a].pb(pii(b, cnt));	
    adj[t][b].pb(pii(a, cnt++));
}

// Only use if graph is guaranteed to have an euler cycle
void euler_dfs(int u, int t){
	temp_path[tsz++] = u;
    while(!adj[t][u].empty()){
        pii ar = adj[t][u].back();
        adj[t][u].pop_back();
		int id = ar.snd;
        if(mrk[id]) continue;
        mrk[id] = 1;
		int v = ar.fst; 
        euler_dfs(v, 1-t);
	}
	final_path[fsz++] = temp_path[--tsz];
}
// Cycle stored in final_path[0...fsz-1]


int pos(pii p){
    return p.fst*(h+1) + p.snd;
}
pii ul(int x, int y){ return {x, y};     }
int UL(int x, int y) { return pos(ul(x,y)); }
pii ur(int x, int y){ return {x+1, y}; }
int UR(int x, int y) { return pos(ur(x, y));}
pii dl(int x, int y){ return {x, y+1}; }
int DL(int x, int y) { return pos(dl(x, y));}
pii dr(int x, int y){ return {x+1, y+1}; }
int DR(int x, int y) { return pos(dr(x, y)); }

int main (){
	scanf("%d%d", &w, &h);
    int u = -1;
	for(int y=0;y<h;y++){
        for(int x=0;x<w;x++){
            //printf("x %d y %d ul %d ur %d dl %d dr %d\n", x, y, UL(x, y), UR(x, y), DL(x, y), DR(x, y));
            scanf(" %c", &M[x][y]);
            if(M[x][y] == 'X'){
                if(u == -1)
                    u = pos(ul(x, y));
                add_edge(1, UL(x, y), DR(x, y));
                add_edge(1, UR(x, y), DL(x, y));
                add_edge(0, UL(x, y), DL(x, y));
                add_edge(0, UR(x, y), DR(x, y));
            }
        }
	}
    euler_dfs(u, 1);
    printf("%d\n", fsz-2);
    reverse(final_path, final_path+fsz);
    for(int a=0;a<fsz-1;a++){
        printf("%d %d\n", final_path[a]/(h+1), final_path[a]%(h+1));
    }
}


