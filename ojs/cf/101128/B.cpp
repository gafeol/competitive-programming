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

const int MAXN = 65*2;

int n, m, k;
int p[MAXN], s[MAXN], deg;
int cy[MAXN];

char c[MAXN][2], A, B, C;

vector<int> adj[MAXN];

inline int mf(char c){
	return ((c == A) || (c == B) || (c == C));
}

void add_edge(char a, int i, char b, int j){
	//debug("add edge %c %d %c %d\n", a, i, b, j);
	int u = (a-'A')*2 + i;
	int v = (b-'A')*2 + j;
	adj[u].pb(v);
}

int pre[MAXN], mrk[MAXN], mn[MAXN], dege;

stack<int> q;

int tarjan(int u){
	q.push(u);
	mrk[u] = 1;
	pre[u] = dege++; 
	mn[u] = pre[u];
	for(int nxt: adj[u]){
		if(!mrk[nxt])
			mn[u] = min(mn[u], tarjan(nxt));
		else if(cy[u] == cy[nxt])
			mn[u] = min(mn[u], pre[nxt]);
	}
	if(mn[u] == pre[u]){
		cy[u] = deg++;
		while(q.top() != u){
			cy[q.top()] = cy[u];
			q.pop();
		}
		q.pop();
	}
	return mn[u];
}

int id(int i, int t){
	return i*2+t;
}

int main (){
	scanf("%d", &n);
	for(int a=0;a<n;a++){
		scanf(" %c %c %d %d", &c[a][0], &c[a][1], &p[a], &s[a]); 
		p[a] -= 1;
	}
	int res =0;
	char zero = 'Z'+1;
	for(A='A';A<='Z';A++){
		for(B=A+1;B<='Z';B++){
			for(C=B+1;C<='Z';C++){
				for(int a=0;a<27*2;a++){
					adj[a].clear();
					mrk[a] = 0;
					cy[a] = -1;
				}
				dege = 0;
				deg = 0;
				int fodeu = 0;
				for(int a=0;a<n;a++){
					int cnt = 0;
					for(int t=0;t<2;t++){
						cnt += mf(c[a][t]); 
					}
					if(s[a] + cnt > 2){
						fodeu = 1;
						break;
					}
					if(s[a] == 2){
						add_edge(zero, (p[a]^1), c[a][0], p[a]);	
						add_edge(c[a][0], (p[a]^1), zero, p[a]);	
						add_edge(zero, (p[a]^1), c[a][0], (p[a]^1));	
						add_edge(c[a][0], (p[a]^1), zero, p[a]);	

						add_edge(zero, (p[a]^1), c[a][1], p[a]);
						add_edge(c[a][1], (p[a]^1), zero, p[a]);
						add_edge(zero, p[a], c[a][1], p[a]);
						add_edge(c[a][1], (p[a]^1), zero, (p[a]^1));
						//conitnue
					}
					else if(s[a] == 1){
						if(cnt == 1){
							char ch = (mf(c[a][0]) ? c[a][1] : c[a][0]);
							add_edge(zero, (p[a]^1), ch, p[a]);
							add_edge(ch, (p[a]^1), zero, p[a]);
						}
						else{
							add_edge(c[a][0], p[a], c[a][1], (p[a]^1));
							add_edge(c[a][1], (p[a]^1), c[a][0], p[a]);
							add_edge(c[a][1], p[a], c[a][0], (p[a]^1));
							add_edge(c[a][0], (p[a]^1), c[a][1], p[a]);
						}
					}
					else{
						if(cnt == 2)
							continue;
						else if(cnt == 1){
							char ch = (mf(c[a][0]) ? c[a][1] : c[a][0]);
							add_edge(zero, p[a], ch, (p[a]^1));
							add_edge(ch, p[a], zero, (p[a]^1));
						}
						else{
							add_edge(zero, p[a], c[a][1], (p[a]^1));
							add_edge(zero, (p[a]^1), c[a][1], (p[a]^1));
							add_edge(zero, p[a], c[a][0], (p[a]^1));
							add_edge(zero, (p[a]^1), c[a][0], (p[a]^1));
						}
					}
				}
				if(fodeu) continue;
				
				for(int a=0;a<2*27;a++){
					if(!mrk[a])
						tarjan(a);
				}
				for(int a=0;a<27;a++){
					if(cy[id(a, 0)] == cy[id(a, 1)]){
//						debug("fodeu pq %d 0 cy %d == %d 1 cy %d\n", a, cy[id(a, 0)], a, cy[id(a, 1)]);
						fodeu = 1;
						break;
					}
				}
//				if(fodeu) debug("B\n");
				if(fodeu) continue;
				res++;
			}
		}
	}
	printf("%d\n", res);
}
