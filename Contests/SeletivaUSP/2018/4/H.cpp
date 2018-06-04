#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
#define fst first
#define snd second

const int MAXN = 51*11 + 51;
const int N = 51*11 + 51;
typedef int num;
const num inf = 100000000;
int n, MA[N], MB[N], PB[N], mn[N];
num c[N][N], d[N];

bool S[N], T[N];
int st[N], sn;
num y[N], z[N];

int s[N];

void reset_all() {
	// need to be changed for costs < 0
	for(int i = 0; i < N; i++)
		y[i] = z[i] = num(0);
	int i;
	for(i = 0; i < n; i++){
		MA[i] = MB[i] = -1;
	}
}

bool increase(int b) {
	int a = PB[b];
	while(true) { // loop infinito
		printf("a %d b %d\n", a, b);
		int n_b = MA[a];
		MB[b] = a;
		MA[a] = b;
		if(n_b == -1) break;
		b = n_b;
		a = PB[b];
	}
	return true;
}

// O(n)
bool visit(int a) {
	S[a] = true;
	for(int b = 0; b < n; b++) {
		if(T[b]) continue;
		if(c[a][b] - y[a] - z[b] < d[b]) {
			d[b] = c[a][b] - y[a] - z[b];
			mn[b] = a;
		}
		if(c[a][b] == y[a] + z[b]) {
			T[b] = true;
			PB[b] = a;
			st[sn++] = b;
			if(MB[b] == -1)
				return increase(b);
		}
	}
	return false;
}

// O(n)
bool update_dual() {
	int mb = -1, b;
	for(b = 0; b < n; b++)
		if(!T[b] && (mb == -1 || d[b] < d[mb]))
			mb = b;
	num e = d[mb];
	for(b = 0; b < n; b++)
		if(T[b]) z[b] -= e;
		else d[b] -= e;
	for(int a = 0; a < n; a++)
		if(S[a]) y[a] += e;
	PB[mb] = mn[mb];
	if(MB[mb] == -1) return increase(mb);
	st[sn++] = mb;
	T[mb] = true;
	return false;
}

// O(n^2)
void find_path() {
	int i, a;
	for(a = 0; MA[a] != -1; a++);
	memset(S, 0, sizeof S);
	memset(T, 0, sizeof T);
	for(int i = 0; i < N; i++) d[i] = inf;
	sn = 0;
	if(visit(a)) return;
	while(true) {
		if(sn) { if(visit(MB[st[--sn]])) break; }
		else if(update_dual()) break;
	}
	puts("ok");
}

num min_match() {
	printf("min match n %d\n", n);
	reset_all();
	for(int i = 0; i < n; i++){
		printf("find path %d\n", i);
		find_path();
	}
	num all = 0;
	for(int a = 0; a < n; a++)
		all += c[a][MA[a]];
	return all;
}

bool cmp(int a, int b){
	return s[a] < s[b];
}

int nn, mm;

int ind[MAXN];

void add(int ii, int jj, int cu){
	int i = nn*mm + ii;
	int j = jj*mm;
	for(int q=1;q<=mm;q++){
		printf("add %d %d\n", i, j+q-1);
		c[i][j+q-1] = q*cu;
	}
}


pii ex[MAXN];

int main() {
	int n, m;
	while(scanf("%d%d", &n, &m) != EOF && n+m != 0){
		nn = n;
		mm = m;
		::n = m + m*n;
		for(int a=0;a<(::n);a++)
			for(int b=0;b<(::n);b++)
				c[a][b] = inf;
		for(int a=0;a<n;a++){
			scanf("%d ", s+a);
			ind[a] = a;
		}
		sort(ind, ind+n, cmp);
		for(int a=0;a<m;a++){
			int t;
			scanf("%d", &t);
			int cnt = 0;
			while(cnt < t){
				int mn, sp; 
				scanf("%d %d", &mn, &sp);
				ex[cnt] = pii(mn, sp);
				cnt++;
			}
			ex[t] = pii(INT_MAX, 0);
			for(int i=0;i<t;i++){
				for(int b=0;b<n;b++){
					if(s[b] >= ex[i].fst && s[b] < ex[i+1].fst){
						add(a, b, ex[i].snd); 
					}
				}
			}
		}
		for(int a=0;a<(::n);a++){
			for(int b=0;b<(::n);b++){
				printf("%10d ", c[a][b]);
			}
			puts("");
		}
		printf("%d\n", min_match());
	}
}
